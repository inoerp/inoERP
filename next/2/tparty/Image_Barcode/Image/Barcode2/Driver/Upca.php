<?php
/* vim: set expandtab tabstop=4 softtabstop=4 shiftwidth=4: */

/**
 * Image_Barcode2_Driver_Upca class
 *
 * Renders UPC-A barcodes
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
 * @author    Didier Fournout <didier.fournout@nyc.fr>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @link      http://pear.php.net/package/Image_Barcode2
 */

require_once __DIR__ . '/../Driver.php';
require_once __DIR__ . '/../Common.php';
require_once __DIR__ . '/../DualWidth.php';
require_once __DIR__ . '/../Exception.php';

/**
 * UPC-A
 *
 * Package which provides a method to create UPC-A barcode using GD library.
 *
 * Slightly Modified Ean13.php to get Upca.php I needed a way to print
 * UPC-A bar codes on a PHP page.  The Image_Barcode2 class seemed like
 * the best way to do it, so I modified ean13 to print in the UPC-A format.
 * Checked the bar code tables against some documentation below (no errors)
 * and validated the changes with my trusty cue-cat.
 * http://www.indiana.edu/~atmat/units/barcodes/bar_t4.htm
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Jeffrey K. Brown <jkb@darkfantastic.net>
 * @author    Didier Fournout <didier.fournout@nyc.fr>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @version   Release: @package_version@
 * @link      http://pear.php.net/package/Image_Barcode2
 */
class Image_Barcode2_Driver_Upca extends Image_Barcode2_Common implements Image_Barcode2_Driver
{
    /**
     * Coding map
     * @var array
     */
    private $_codingmap = array(
        '0' => array(
            'L' => array(0,0,0,1,1,0,1),
            'R' => array(1,1,1,0,0,1,0)
        ),
        '1' => array(
            'L' => array(0,0,1,1,0,0,1),
            'R' => array(1,1,0,0,1,1,0)
        ),
        '2' => array(
            'L' => array(0,0,1,0,0,1,1),
            'R' => array(1,1,0,1,1,0,0)
        ),
        '3' => array(
            'L' => array(0,1,1,1,1,0,1),
            'R' => array(1,0,0,0,0,1,0)
        ),
        '4' => array(
            'L' => array(0,1,0,0,0,1,1),
            'R' => array(1,0,1,1,1,0,0)
        ),
        '5' => array(
            'L' => array(0,1,1,0,0,0,1),
            'R' => array(1,0,0,1,1,1,0)
        ),
        '6' => array(
            'L' => array(0,1,0,1,1,1,1),
            'R' => array(1,0,1,0,0,0,0)
        ),
        '7' => array(
            'L' => array(0,1,1,1,0,1,1),
            'R' => array(1,0,0,0,1,0,0)
        ),
        '8' => array(
            'L' => array(0,1,1,0,1,1,1),
            'R' => array(1,0,0,1,0,0,0)
        ),
        '9' => array(
            'L' => array(0,0,0,1,0,1,1),
            'R' => array(1,1,1,0,1,0,0)
        )
    );

    /**
     * Class constructor
     *
     * @param Image_Barcode2_Writer $writer Library to use.
     */
    public function __construct(Image_Barcode2_Writer $writer) 
    {
        parent::__construct($writer);
        $this->setBarcodeHeight(50);
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
        // Check barcode for invalid characters
        if (!preg_match('/^[0-9]{12}$/', $this->getBarcode())) {
            throw new Image_Barcode2_Exception('Invalid barcode');
        }
    }


    /**
     * Draws a UPC-A image barcode
     *
     * @return resource            The corresponding UPC-A image barcode
     *
     * @author  Jeffrey K. Brown <jkb@darkfantastic.net>
     * @author  Didier Fournout <didier.fournout@nyc.fr>
     */
    public function draw()
    {
        $text     = $this->getBarcode();
        $writer   = $this->getWriter();
        $fontsize = $this->getFontSize();

        // Calculate the barcode width
        $barcodewidth = (strlen($text)) * (7 * $this->getBarcodeWidth())
            + 3 // left
            + 5 // center
            + 3 // right
            + $writer->imagefontwidth($fontsize) + 1
            + $writer->imagefontwidth($fontsize) + 1 // check digit padding
            ;


        $barcodelongheight = (int)($writer->imagefontheight($fontsize) / 2)
            + $this->getBarcodeHeight();

        // Create the image
        $img = $writer->imagecreate(
            $barcodewidth,
            $barcodelongheight + $writer->imagefontheight($fontsize) + 1
        );

        // Alocate the black and white colors
        $black = $writer->imagecolorallocate($img, 0, 0, 0);
        $white = $writer->imagecolorallocate($img, 255, 255, 255);

        // Fill image with white color
        $writer->imagefill($img, 0, 0, $white);

        // get the first digit which is the key for creating the first 6 bars
        $key = substr($text, 0, 1);

        // Initiate x position
        $xpos = 0;

        // print first digit
        if ($this->showText) {
            $writer->imagestring(
                $img,
                $fontsize,
                $xpos,
                $this->getBarcodeHeight(),
                $key,
                $black
            );
        }
        $xpos = $writer->imagefontwidth($fontsize) + 1;


        // Draws the left guard pattern (bar-space-bar)
        // bar
        $writer->imagefilledrectangle(
            $img,
            $xpos,
            0,
            $xpos + $this->getBarcodeWidth() - 1,
            $barcodelongheight,
            $black
        );

        $xpos += $this->getBarcodeWidth();
        // space
        $xpos += $this->getBarcodeWidth();
        // bar
        $writer->imagefilledrectangle(
            $img,
            $xpos,
            0,
            $xpos + $this->getBarcodeWidth() - 1,
            $barcodelongheight,
            $black
        );

        $xpos += $this->getBarcodeWidth();


        foreach ($this->_codingmap[$key]['L'] as $bar) {
            if ($bar) {
                $writer->imagefilledrectangle(
                    $img,
                    $xpos,
                    0,
                    $xpos + $this->getBarcodeWidth() - 1,
                    $barcodelongheight,
                    $black
                );
            }
            $xpos += $this->getBarcodeWidth();
        }



        // Draw left $text contents
        for ($idx = 1; $idx < 6; $idx ++) {
            $value = substr($text, $idx, 1);

            if ($this->showText) {
                $writer->imagestring(
                    $img,
                    $fontsize,
                    $xpos + 1,
                    $this->getBarcodeHeight(),
                    $value,
                    $black
                );
            }

            foreach ($this->_codingmap[$value]['L'] as $bar) {
                if ($bar) {
                    $writer->imagefilledrectangle(
                        $img,
                        $xpos,
                        0,
                        $xpos + $this->getBarcodeWidth() - 1,
                        $this->getBarcodeHeight(),
                        $black
                    );
                }
                $xpos += $this->getBarcodeWidth();
            }
        }


        // Draws the center pattern (space-bar-space-bar-space)
        // space
        $xpos += $this->getBarcodeWidth();
        // bar
        $writer->imagefilledrectangle(
            $img,
            $xpos,
            0,
            $xpos + $this->getBarcodeWidth() - 1,
            $barcodelongheight,
            $black
        );
        $xpos += $this->getBarcodeWidth();
        // space
        $xpos += $this->getBarcodeWidth();
        // bar
        $writer->imagefilledrectangle(
            $img,
            $xpos,
            0,
            $xpos + $this->getBarcodeWidth() - 1,
            $barcodelongheight,
            $black
        );
        $xpos += $this->getBarcodeWidth();
        // space
        $xpos += $this->getBarcodeWidth();


        // Draw right $text contents
        for ($idx = 6; $idx < 11; $idx ++) {
            $value = substr($text, $idx, 1);

            if ($this->showText) {
                $writer->imagestring(
                    $img,
                    $fontsize,
                    $xpos + 1,
                    $this->getBarcodeHeight(),
                    $value,
                    $black
                );
            }

            foreach ($this->_codingmap[$value]['R'] as $bar) {
                if ($bar) {
                    $writer->imagefilledrectangle(
                        $img,
                        $xpos,
                        0,
                        $xpos + $this->getBarcodeWidth() - 1,
                        $this->getBarcodeHeight(),
                        $black
                    );
                }
                $xpos += $this->getBarcodeWidth();
            }
        }



        $value = substr($text, 11, 1);
        foreach ($this->_codingmap[$value]['R'] as $bar) {
            if ($bar) {
                $writer->imagefilledrectangle(
                    $img,
                    $xpos,
                    0,
                    $xpos + $this->getBarcodeWidth() - 1,
                    $barcodelongheight,
                    $black
                );

            }
            $xpos += $this->getBarcodeWidth();
        }



        // Draws the right guard pattern (bar-space-bar)
        // bar
        $writer->imagefilledrectangle(
            $img,
            $xpos,
            0,
            $xpos + $this->getBarcodeWidth() - 1,
            $barcodelongheight,
            $black
        );

        $xpos += $this->getBarcodeWidth();
        // space
        $xpos += $this->getBarcodeWidth();
        // bar
        $writer->imagefilledrectangle(
            $img,
            $xpos,
            0,
            $xpos + $this->getBarcodeWidth() - 1,
            $barcodelongheight,
            $black
        );

        $xpos += $this->getBarcodeWidth();


        // Print Check Digit
        if ($this->showText) {
            $writer->imagestring(
                $img,
                $fontsize,
                $xpos + 1,
                $this->getBarcodeHeight(),
                $value,
                $black
            );
        }

        return $img;
    }

} // class
