<?php

/* vim: set expandtab tabstop=4 softtabstop=4 shiftwidth=4: */

/**
 * Image_Barcode2_Driver_Int25 class
 *
 * Renders Interleaved 2 of 5 barcodes
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
 * @author    Marcelo Subtil Marcal <msmarcal@php.net>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @link      http://pear.php.net/package/Image_Barcode2
 */
require_once __DIR__ . '/../Driver.php';
require_once __DIR__ . '/../Common.php';
require_once __DIR__ . '/../DualWidth.php';
require_once __DIR__ . '/../Exception.php';

/**
 * Interleaved 2 of 5
 *
 * Package which provides a method to create Interleaved 2 of 5
 * barcode using GD library.
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Marcelo Subtil Marcal <msmarcal@php.net>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @version   Release: @package_version@
 * @link      http://pear.php.net/package/Image_Barcode2
 */
class Image_Barcode2_Driver_Int25 extends Image_Barcode2_Common implements Image_Barcode2_Driver, Image_Barcode2_DualWidth {

 /**
  * Coding map
  * @var array
  */
 private $_codingmap = array(
  '0' => '00110',
  '1' => '10001',
  '2' => '01001',
  '3' => '11000',
  '4' => '00101',
  '5' => '10100',
  '6' => '01100',
  '7' => '00011',
  '8' => '10010',
  '9' => '01010'
 );

 /**
  * Class constructor
  *
  * @param Image_Barcode2_Writer $writer Library to use.
  */
 public function __construct(Image_Barcode2_Writer $writer) {
  parent::__construct($writer);
  $this->setBarcodeHeight(50);
  $this->setBarcodeWidthThin(1);
  $this->setBarcodeWidthThick(3);
 }

 /**
  * Validate barcode
  *
  * @return void
  * @throws Image_Barcode2_Exception
  */
 public function validate() {
  // Check barcode for invalid characters
  if (!preg_match('/[0-9]/', $this->getBarcode())) {
   throw new Image_Barcode2_Exception('Invalid barcode');
  }
 }

 /**
  * Draws a Interleaved 2 of 5 image barcode
  *
  * @return resource            The corresponding Interleaved 2 of 5 image barcode
  *
  * @access public
  *
  * @author Marcelo Subtil Marcal <msmarcal@php.net>
  * @since  Image_Barcode2 0.3
  */
 public function draw() {
  $text = $this->getBarcode();
  $writer = $this->getWriter();

  // if odd $text lenght adds a '0' at string beginning
  $text = strlen($text) % 2 ? '0' . $text : $text;

  // Calculate the barcode width
  $barcodewidth = (strlen($text)) * (3 * $this->getBarcodeWidthThin() + 2 * $this->getBarcodeWidthThick()) + (strlen($text)) * 2.5 + (7 * $this->getBarcodeWidthThin() + $this->getBarcodeWidthThick()) + 3;

  // Create the image
  $img = $writer->imagecreate($barcodewidth, $this->getBarcodeHeight());

  // Alocate the black and white colors
  $black = $writer->imagecolorallocate($img, 0, 0, 0);
  $white = $writer->imagecolorallocate($img, 255, 255, 255);

  // Fill image with white color
  $writer->imagefill($img, 0, 0, $white);

  // Initiate x position
  $xpos = 0;

  // Draws the leader
  for ($i = 0; $i < 2; $i++) {
   $elementwidth = $this->getBarcodeWidthThin();
   $writer->imagefilledrectangle(
    $img, $xpos, 0, $xpos + $elementwidth - 1, $this->getBarcodeHeight(), $black
   );
   $xpos += $elementwidth;
   $xpos += $this->getBarcodeWidthThin();
   $xpos ++;
  }

  // Draw $text contents
  $all = strlen($text);

  // Draw 2 chars at a time
  for ($idx = 0; $idx < $all; $idx += 2) {
   $oddchar = substr($text, $idx, 1);
   $evenchar = substr($text, $idx + 1, 1);

   // interleave
   for ($baridx = 0; $baridx < 5; $baridx++) {

    // Draws odd char corresponding bar (black)
    $elementwidth = $this->getBarcodeWidthThin();
    if (substr($this->_codingmap[$oddchar], $baridx, 1)) {
     $elementwidth = $this->getBarcodeWidthThick();
    }

    $writer->imagefilledrectangle(
     $img, $xpos, 0, $xpos + $elementwidth - 1, $this->getBarcodeHeight(), $black
    );

    $xpos += $elementwidth;

    // Left enought space to draw even char (white)
    $elementwidth = $this->getBarcodeWidthThin();
    if (substr($this->_codingmap[$evenchar], $baridx, 1)) {
     $elementwidth = $this->getBarcodeWidthThick();
    }

    $xpos += $elementwidth;
    $xpos ++;
   }
  }


  // Draws the trailer
  $elementwidth = $this->getBarcodeWidthThick();
  $writer->imagefilledrectangle(
   $img, $xpos, 0, $xpos + $elementwidth - 1, $this->getBarcodeHeight(), $black
  );
  $xpos += $elementwidth;
  $xpos += $this->getBarcodeWidthThin();
  $xpos ++;
  $elementwidth = $this->getBarcodeWidthThin();
  $writer->imagefilledrectangle(
   $img, $xpos, 0, $xpos + $elementwidth - 1, $this->getBarcodeHeight(), $black
  );

  return $img;
 }

}

// class
