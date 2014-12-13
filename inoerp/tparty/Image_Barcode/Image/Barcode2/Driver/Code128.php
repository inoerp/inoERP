<?php
/* vim: set expandtab tabstop=4 softtabstop=4 shiftwidth=4: */

/**
 * Image_Barcode2_Driver_Code128 class
 *
 * Renders Code128 barcodes
 * Code128 is a high density encoding for alphanumeric strings.
 * This module prints the Code128B representation of the most common
 * ASCII characters (32 to 134).
 *
 * These are the components of a Code128 Bar code:
 * - 10 Unit Quiet Zone
 * - 6 Unit Start Character
 * - (n * 6) Unit Message
 * - 6 Unit "Check Digit" Character
 * - 7 Unit Stop Character
 * - 10 Unit Quiet Zone
 *
 * I originally wrote this algorithm in Visual Basic 6 for a Rapid 
 * Software Development class, where we printed Code128 B bar codes
 * to read using Cue Cat bar code readers.  I rewrote the algorithm
 * using PHP for inclusion in the PEAR Image_Barcode2 project.
 *
 * The Code128B bar codes produced by the algorithm have been validated
 * using my trusty Cue-Cat bar code reader.
 *
 * PHP versions 5
 *
 * LICENSE: This source file is subject to version 3.0 of the PHP license
 * that is available through the world-wide-web at the following URI:
 * http://www.php.net/license/3_0.txt.  If you did not receive a copy of
 * the PHP License and are unable to obtain it through the web, please
 * send a note to license@php.net so we can mail you a copy immediately.
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Jeffrey K. Brown <jkb@darkfantastic.net>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @link      http://pear.php.net/package/Image_Barcode2
 */

require_once __DIR__ . '/../Driver.php';
require_once __DIR__ . '/../Common.php';
require_once __DIR__ . '/../DualWidth.php';
require_once __DIR__ . '/../Exception.php';

/**
 * Code128
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Jeffrey K. Brown <jkb@darkfantastic.net>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @link      http://pear.php.net/package/Image_Barcode2
 */

class Image_Barcode2_Driver_Code128 extends Image_Barcode2_Common implements Image_Barcode2_Driver
{
    /**
     * Coding map
     * @var array
     */
    private $_codingmap = array(
        0 => '212222',  // " "
        1 => '222122',  // "!"
        2 => '222221',  // "{QUOTE}"
        3 => '121223',  // "#"
        4 => '121322',  // "$"
        5 => '131222',  // "%"
        6 => '122213',  // "&"
        7 => '122312',  // "'"
        8 => '132212',  // "("
        9 => '221213',  // ")"
        10 => '221312', // "*"
        11 => '231212', // "+"
        12 => '112232', // ","
        13 => '122132', // "-"
        14 => '122231', // "."
        15 => '113222', // "/"
        16 => '123122', // "0"
        17 => '123221', // "1"
        18 => '223211', // "2"
        19 => '221132', // "3"
        20 => '221231', // "4"
        21 => '213212', // "5"
        22 => '223112', // "6"
        23 => '312131', // "7"
        24 => '311222', // "8"
        25 => '321122', // "9"
        26 => '321221', // ":"
        27 => '312212', // ";"
        28 => '322112', // "<"
        29 => '322211', // "="
        30 => '212123', // ">"
        31 => '212321', // "?"
        32 => '232121', // "@"
        33 => '111323', // "A"
        34 => '131123', // "B"
        35 => '131321', // "C"
        36 => '112313', // "D"
        37 => '132113', // "E"
        38 => '132311', // "F"
        39 => '211313', // "G"
        40 => '231113', // "H"
        41 => '231311', // "I"
        42 => '112133', // "J"
        43 => '112331', // "K"
        44 => '132131', // "L"
        45 => '113123', // "M"
        46 => '113321', // "N"
        47 => '133121', // "O"
        48 => '313121', // "P"
        49 => '211331', // "Q"
        50 => '231131', // "R"
        51 => '213113', // "S"
        52 => '213311', // "T"
        53 => '213131', // "U"
        54 => '311123', // "V"
        55 => '311321', // "W"
        56 => '331121', // "X"
        57 => '312113', // "Y"
        58 => '312311', // "Z"
        59 => '332111', // "["
        60 => '314111', // "\"
        61 => '221411', // "]"
        62 => '431111', // "^"
        63 => '111224', // "_"
        64 => '111422', // "`"
        65 => '121124', // "a"
        66 => '121421', // "b"
        67 => '141122', // "c"
        68 => '141221', // "d"
        69 => '112214', // "e"
        70 => '112412', // "f"
        71 => '122114', // "g"
        72 => '122411', // "h"
        73 => '142112', // "i"
        74 => '142211', // "j"
        75 => '241211', // "k"
        76 => '221114', // "l"
        77 => '413111', // "m"
        78 => '241112', // "n"
        79 => '134111', // "o"
        80 => '111242', // "p"
        81 => '121142', // "q"
        82 => '121241', // "r"
        83 => '114212', // "s"
        84 => '124112', // "t"
        85 => '124211', // "u"
        86 => '411212', // "v"
        87 => '421112', // "w"
        88 => '421211', // "x"
        89 => '212141', // "y"
        90 => '214121', // "z"
        91 => '412121', // "{"
        92 => '111143', // "|"
        93 => '111341', // "}"
        94 => '131141', // "~"
        95 => '114113', // 95
        96 => '114311', // 96
        97 => '411113', // 97
        98 => '411311', // 98
        99 => '113141', // 99
        100 => '114131', // 100
        101 => '311141', // 101
        102 => '411131', // 102
    );

    /**
     * Class constructor
     *
     * @param Image_Barcode2_Writer $writer Library to use.
     */
    public function __construct(Image_Barcode2_Writer $writer) 
    {
        parent::__construct($writer);
        $this->setBarcodeHeight(60);
        $this->setBarcodeWidth(1);
    }


    /**
     * Validate barcode
     *
     * @return void
     * @throws Image_Barcode2_Exception
     */
    public function validate()
    {
        //
    }


    /**
     * Draws a Code128 image barcode
     *
     * @return resource            The corresponding Code128 image barcode
     *
     * @access public
     *
     * @author Jeffrey K. Brown <jkb@darkfantastic.net>
     *
     * @internal
     * The draw() method is broken into three sections.  First, we take
     * the input string and convert it to a string of barcode widths.
     * Then, we size and allocate the image.  Finally, we print the bars to
     * the image along with the barcode text and display it to the beholder.
     */
    public function draw()
    {
        // We start with the Code128 Start Code character.  We
        // initialize checksum to 104, rather than calculate it.
        // We then add the startcode to $allbars, the main string
        // containing the bar sizes for the entire code.
        $startcode = $this->_getStartCode();
        $checksum  = 104;
        $allbars   = $startcode;
        $text      = $this->getBarcode();
        $writer    = $this->getWriter();
        $fontsize  = $this->getFontSize();


        // Next, we read the barcode string that was passed to the
        // method and for each character, we determine the bar
        // pattern and add it to the end of the $allbars string.
        // In addition, we continually add the character's value
        // to the checksum
        for ($i = 0, $all = strlen($text); $i < $all; ++$i) {
            $char = $text[$i];
            $val = $this->_getCharNumber($char);

            $checksum += ($val * ($i + 1));

            $allbars .= $this->_getCharCode($char);
        }


        // Then, Take the Mod 103 of the total to get the index
        // of the Code128 Check Character.  We get its bar
        // pattern and add it to $allbars in the next section.
        $checkdigit = $checksum % 103;
        $bars = $this->_getNumCode($checkdigit);


        // Finally, we get the Stop Code pattern and put the
        // remaining pieces together.  We are left with the
        // string $allbars containing all of the bar widths
        // and can now think about writing it to the image.

        $stopcode = $this->_getStopCode();
        $allbars = $allbars . $bars . $stopcode;

        //------------------------------------------------------//
        // Next, we will calculate the width of the resulting
        // bar code and size the image accordingly.

        // 10 Pixel "Quiet Zone" in front, and 10 Pixel
        // "Quiet Zone" at the end.
        $barcodewidth = 20;


        // We will read each of the characters (1,2,3,or 4) in
        // the $allbars string and add its width to the running
        // total $barcodewidth.  The height of the barcode is
        // calculated by taking the bar height plus the font height.

        for ($i = 0, $all = strlen($allbars); $i < $all; ++$i) {
            $nval = $allbars[$i];
            $barcodewidth += ($nval * $this->getBarcodeWidth());
        }

        $barcodelongheight = (int)($writer->imagefontheight($fontsize) / 2)
            + $this->getBarcodeHeight();


        // Then, we create the image, allocate the colors, and fill
        // the image with a nice, white background, ready for printing
        // our black bars and the text.

        $img = $writer->imagecreate(
            $barcodewidth,
            $barcodelongheight + $writer->imagefontheight($fontsize) + 1
        );
        $black = $writer->imagecolorallocate($img, 0, 0, 0);
        $white = $writer->imagecolorallocate($img, 255, 255, 255);
        $writer->imagefill($img, 0, 0, $white);


        //------------------------------------------------------//
        // Finally, we write our text line centered across the
        // bottom and the bar patterns and display the image.


        // First, print the image, centered across the bottom.
        if ($this->showText) {
            $writer->imagestring(
                $img,
                $fontsize,
                $barcodewidth / 2 - strlen($text) / 2 * ($writer->imagefontwidth($fontsize)),
                $this->getBarcodeHeight() + $writer->imagefontheight($fontsize) / 2,
                $text,
                $black
            );
        }

        // We set $xpos to 10 so we start bar printing after 
        // position 10 to simulate the 10 pixel "Quiet Zone"
        $xpos = 10;

        // We will now process each of the characters in the $allbars
        // array.  The number in each position is read and then alternating
        // black bars and spaces are drawn with the corresponding width.
        $bar = 1;
        for ($i = 0, $all = strlen($allbars); $i < $all; ++$i) {
            $nval = $allbars[$i];
            $width = $nval * $this->getBarcodeWidth();

            if ($bar == 1) {
                $writer->imagefilledrectangle(
                    $img, 
                    $xpos, 
                    0, 
                    $xpos + $width - 1, 
                    $barcodelongheight, 
                    $black
                );
                $xpos += $width;
                $bar = 0;
            } else {
                $xpos += $width;
                $bar = 1;
            }
        }

        return $img;
    }


    /**
     * Get the Code128 code for a character
     *
     * @param string $char Chacter
     *
     * @return string
     */
    private function _getCharCode($char)
    {
        return $this->_codingmap[ord($char) - 32];
    }


    /**
     * Get the Start Code for Code128
     *
     * @return string
     */
    private function _getStartCode()
    {
        return '211214';
    }


    /**
     * Get the Stop Code for Code128
     *
     * @return string
     */
    private function _getStopCode()
    {
        return '2331112';
    }


    /**
     * Rhe Code128 code equivalent of a character number
     *
     * @param int $index Index
     *
     * @return string 
     */
    private function _getNumCode($index)
    {
        return $this->_codingmap[$index];
    }


    /**
     * Get the Code128 numerical equivalent of a character.
     *
     * @param string $char Character
     *
     * @return int
     */
    private function _getCharNumber($char)
    {
        return ord($char) - 32;
    }

} // class
