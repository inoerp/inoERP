<?php
/* vim: set expandtab tabstop=4 softtabstop=4 shiftwidth=4: */

/**
 * Image_Barcode2_Common class
 *
 * Common code
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
 * Image_Barcode2_Common class
 *
 * Common code
 *
 * @category  Image
 * @package   Image_Barcode2
 * @author    Ryan Briones <ryanbriones@webxdesign.org>
 * @copyright 2005 The PHP Group
 * @license   http://www.php.net/license/3_0.txt  PHP License 3.0
 * @version   Release: @package_version@
 * @link      http://pear.php.net/package/Image_Barcode2
 */
class Image_Barcode2_Common
{
    protected $barcodeheight;
    protected $barcodewidth;
    protected $barcodethinwidth;
    protected $barcodethickwidth;
    protected $fontsize = 2;
    protected $showText;

    /**
     * @var Image_Barcode2_Writer
     */
    protected $writer;
    
    /**
     * @var string barcode
     */
    protected $barcode;


    /**
     * Class constructor
     *
     * @param Image_Barcode2_Writer $writer Library to use.
     */
    public function __construct(Image_Barcode2_Writer $writer) 
    {
        $this->setWriter($writer);
    }

    /**
     * Set the image rendering library.
     *
     * @param Image_Barcode2_Writer $writer Library to use.
     *
     * @return void
     */
    public function setWriter(Image_Barcode2_Writer $writer) 
    {
        $this->writer = $writer;
    }

    /**
     * Get the image rendering library.
     *
     * @return Image_Barcode2_Writer
     */
    public function getWriter() 
    {
        return $this->writer;
    }

    /**
     * Set the barcode
     *
     * @param string $barcode barcode
     *
     * @return void
     */
    public function setBarcode($barcode) 
    {
        $this->barcode = trim($barcode);
    }

    /**
     * Get the barcode
     *
     * @return string
     */
    public function getBarcode() 
    {
        return $this->barcode;
    }

    /**
     * Set if text will be placed under the barcode
     *
     * @param boolean $showText The text should be placed under barcode
     *
     * @return void
     */
    public function setShowText($showText) 
    {
        $this->showText = $showText;
    }

    /**
     * Get if text will be placed under the barcode
     *
     * @return boolean
     */
    public function getShowText() 
    {
        return $this->showText;
    }

    public function setFontSize($size)
    {
        $this->fontsize = $size;
    }

    public function getFontSize()
    {
        return $this->fontsize;
    }

    public function setBarcodeHeight($height) 
    {
        $this->barcodeheight = $height;
    }

    public function getBarcodeHeight()
    {
        return $this->barcodeheight;
    }

    public function setBarcodeWidth($width)
    {
        $this->barcodewidth = $width;
    }

    public function getBarcodeWidth()
    {
        return $this->barcodewidth;
    }

    public function setBarcodeWidthThick($width)
    {
        $this->barcodethickwidth = $width;
    }

    public function getBarcodeWidthThick()
    {
        return $this->barcodethickwidth;
    }

    public function setBarcodeWidthThin($width)
    {
        $this->barcodethinwidth = $width;
    }

    public function getBarcodeWidthThin()
    {
        return $this->barcodethinwidth;
    }
}
