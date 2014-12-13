<?php
/* vim: set expandtab tabstop=4 softtabstop=4 shiftwidth=4: */

/**
 * Image_Barcode2 class
 *
 * Package to render barcodes
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

require_once 'Barcode2/Writer.php';
require_once 'Barcode2/Driver.php';
require_once 'Barcode2/Exception.php';

/**
 * Image_Barcode2 class
 *
 * Package which provides a method to create barcode using GD library.
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Marcelo Subtil Marcal <msmarcal@php.net>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @version   Release: @package_version@
 * @link      http://pear.php.net/package/Image_Barcode2
 */
class Image_Barcode2
{
    /**
     * Image type
     */
    const IMAGE_PNG     = 'png';
    const IMAGE_GIF     = 'gif';
    const IMAGE_JPEG    = 'jpg';

    /**
     * Barcode type
     */
    const BARCODE_CODE39    = 'code39';
    const BARCODE_INT25     = 'int25';
    const BARCODE_EAN13     = 'ean13';
    const BARCODE_UPCA      = 'upca';
    const BARCODE_UPCE      = 'upce';
    const BARCODE_CODE128   = 'code128';
    const BARCODE_EAN8      = 'ean8';
    const BARCODE_POSTNET   = 'postnet';

    /**
     * Rotation type
     */
    const ROTATE_NONE     = 0;
    const ROTATE_RIGHT    = 90;
    const ROTATE_UTURN    = 180;
    const ROTATE_LEFT     = 270;


    /**
     * Draws a image barcode
     *
     * @param string  $text           A text that should be in the image barcode
     * @param string  $type           The barcode type. Supported types:
     *                                code39 - Code 3 of 9
     *                                int25  - 2 Interleaved 5
     *                                ean13  - EAN 13
     *                                upca   - UPC-A
     *                                upce   - UPC-E
     *                                code128
     *                                ean8
     *                                postnet
     * @param string  $imgtype        The image type that will be generated
     *                                (gif, jpg, png)
     * @param boolean $bSendToBrowser if the image shall be outputted to the
     *                                 browser, or be returned.
     * @param integer $height         The image height
     * @param integer $width          The image width
     * @param boolean $showText       The text should be placed under barcode
     * @param integer $rotation       The rotation angle
     *
     * @return resource The corresponding gd image resource
     *               
     * @throws Image_Barcode2_Exception
     * @access public
     *
     * @author Marcelo Subtil Marcal <msmarcal@php.net>
     * @since  Image_Barcode2 0.3
     */
    public static function draw($text, 
        $type = Image_Barcode2::BARCODE_INT25,
        $imgtype = Image_Barcode2::IMAGE_PNG, 
        $bSendToBrowser = true,
        $height = 60,
        $width = 1,
        $showText = true,
        $rotation = Image_Barcode2::ROTATE_NONE
    ) {
        //Make sure no bad files are included
        if (!preg_match('/^[a-zA-Z0-9]+$/', $type)) {
            throw new Image_Barcode2_Exception('Invalid barcode type ' . $type);
        }

        if (!include_once 'Barcode2/Driver/' . ucfirst($type) . '.php') {
            throw new Image_Barcode2_Exception($type . ' barcode is not supported');
        }

        $classname = 'Image_Barcode2_Driver_' . ucfirst($type);

        $obj = new $classname(new Image_Barcode2_Writer());

        if (!$obj instanceof Image_Barcode2_Driver) {
            throw new Image_Barcode2_Exception(
                "'$classname' does not implement Image_Barcode2_Driver"
            );
        }

        if (!$obj instanceof Image_Barcode2_DualWidth) {
            $obj->setBarcodeWidth($width);
        }

        if (!$obj instanceof Image_Barcode2_DualHeight) {
            $obj->setBarcodeHeight($height);
        }

        $obj->setBarcode($text);
        $obj->setShowText($showText);

        $obj->validate();
        $img = $obj->draw();

        // Rotate image on demand
        if ($rotation !== self::ROTATE_NONE) {
            $img = imagerotate($img, $rotation, 0);
        }

        if ($bSendToBrowser) {
            // Send image to browser
            switch ($imgtype) {
            case self::IMAGE_GIF:
                header('Content-type: image/gif');
                imagegif($img);
                imagedestroy($img);
                break;

            case self::IMAGE_JPEG:
                header('Content-type: image/jpg');
                imagejpeg($img);
                imagedestroy($img);
                break;

            default:
                header('Content-type: image/png');
                imagepng($img);
                imagedestroy($img);
                break;
            }
        }

        return $img;
    }
}
