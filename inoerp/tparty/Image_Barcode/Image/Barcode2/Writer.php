<?php
/* vim: set expandtab tabstop=4 softtabstop=4 shiftwidth=4: */

/**
 * Image_Barcode2_Writer class
 *
 * An adapter for the non oo image writing code.
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
 * @author    Ryan Briones <ryanbriones@webxdesign.org>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @link      http://pear.php.net/package/Image_Barcode2
 */
/**
 * Image_Barcode2_Writer class
 *
 * An adapter for the non oo image writing code.
 * Just used to create a seam for phpunit
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Ryan Briones <ryanbriones@webxdesign.org>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @version   Release: @package_version@
 * @link      http://pear.php.net/package/Image_Barcode2
 * @todo See if http://pear.php.net/package/Image_Canvas can be made to work well
 */
class Image_Barcode2_Writer
{
    public function imagecreate($width, $height)
    {
        return imagecreate($width, $height);
    }

    public function imagestring($image, $font, $x, $y, $string, $color)
    {
        return imagestring($image, $font, $x, $y, $string, $color);
    }

    public function imagefill($image, $x, $y, $color)
    {
        return imagefill($image, $x, $y, $color);
    }

    public function imagefilledrectangle($image, $x1, $y1, $x2, $y2, $color)
    {
        return imagefilledrectangle($image, $x1, $y1, $x2, $y2, $color);
    }

    public function imagefontheight($font)
    {
        return imagefontheight($font);
    }

    public function imagefontwidth($font)
    {
        return imagefontwidth($font);
    }

    public function imagecolorallocate($image, $red, $green, $blue)
    {
        return imagecolorallocate($image, $red, $green, $blue);
    }

    public function imageline($image, $x1, $y1, $x2, $y2, $color)
    {
        return imageline($image, $x1, $y1, $x2, $y2, $color);
    }
}
