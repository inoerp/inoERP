= Image_Barcode2 - a package to render barcodes =
------------------------------------------------

With PEAR::Image_Barcode2 class you can create a barcode representation of a
given string.

This class uses GD function because this the generated graphic can be any of
GD supported supported image types.


= Installation =
----------------

You can install Image_Barcode2 issuing the following command (as root):

    # pear install Image_Barcode2

If you don't have the 'pear' command, please consult PEAR::The PHP Extension and
Application Repository homepage at http://pear.php.net


= Getting Started =
-------------------

Just load the class in your script:

    require_once('Image/Barcode2.php');

Call the Image_Barcode2::draw() as the follow:

    Image_Barcode2::draw('1234', 'int25', 'png');

Where:

= '1234' : string you want to draw as barcode;
= 'int25': barcode type (check the avaible types at 'Barcode' subdir);
= 'png'  : generated graphic type.


= Current State =
-----------------

You can get the latest code at the PEAR site:
    http://pear.php.net/package/Image_Barcode2/


= Contributing =
----------------

Help from people who want code new barcode module types are very welcome. Just
send your module directly to msmarcal@php.net


= Credits =
-----------

Core class
    written by Marcelo Subtil Marcal <msmarcal@php.net>

Interleaved 2 of 5 barcode module type
    written by Marcelo Subtil Marcal <msmarcal@php.net>

EAN13 barcode module type
    written by Didier FOURNOUT <didier.fournout@nyc.fr>

Code39 barcode module type
    written by Ryan Briones <ryanbriones@webxdesign.org>

UPC-A and Code128 barcode modules
    written by Jeffrey K. Brown <jkb@darkfantastic.net>

PostNet barcode module type
    written by Josef "Jeff" Sipek <jeffpc@optonline.net>


= Thanks to =
-------------

Mark A.R. <mark@mark.org.il>


= Author =
----------

Written by Marcelo Subtil Marcal <msmarcal@php.net>


= Reporting Bugs =
------------------

Report bugs at: http://pear.php.net/bugs/report.php?package=Image_Barcode2
