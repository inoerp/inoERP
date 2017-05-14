<?php
/* vim: set expandtab tabstop=4 softtabstop=4 shiftwidth=4: */

/**
 * Image_Barcode2_Driver interface
 *
 * Driver code
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
 * Image_Barcode2_Driver interface
 *
 * Driver code
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Ryan Briones <ryanbriones@webxdesign.org>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @version   Release: @package_version@
 * @link      http://pear.php.net/package/Image_Barcode2
 */
interface Image_Barcode2_Driver
{
    /**
     * Draws a barcode
     *
     * @return resource            The corresponding image barcode
     */
    public function draw();

    /**
     * Set the image rendering library.
     *
     * @param Image_Barcode2_Writer $writer Library to use.
     *
     * @return void
     */
    public function setWriter(Image_Barcode2_Writer $writer);

    /**
     * Set barcode
     *
     * @param string $barcode barcode
     *
     * @return void
     */
    public function setBarcode($barcode);

    /**
     * Validate barcode
     *
     * @return void
     * @throws Image_Barcode2_Exception
     */
    public function validate();
}
