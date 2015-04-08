<?php
include_once("config.php");
?>
<style type="text/css">
<!--
body{font-family: arial;color: #7A7A7A;margin:0px;padding:0px;}
.procut_item {width: 550px;margin-right: auto;margin-left: auto;padding: 20px;background: #F1F1F1;margin-bottom: 1px;font-size: 12px;border-radius: 5px;text-shadow: 1px 1px 1px #FCFCFC;}
.procut_item h4 {margin: 0px;padding: 0px;font-size: 20px;}
-->
</style>

<h2 align="center">Test Products</h2>
<div class="product_wrapper">
<table class="procut_item" border="0" cellpadding="4">
  <tr>
    <td width="70%"><h4>Canon EOS Rebel XS</h4>(Capture all your special moments with the Canon EOS Rebel XS/1000D DSLR camera and cherish the memories over and over again.)</td>
    <td width="30%">
    <form method="post" action="process.php">
	<input type="hidden" name="itemname" value="Canon EOS Rebel XS" /> 
	<input type="hidden" name="itemnumber" value="10000" /> 
    <input type="hidden" name="itemdesc" value="Capture all your special moments with the Canon EOS Rebel XS/1000D DSLR camera and cherish the memories over and over again." /> 
	<input type="hidden" name="itemprice" value="225.00" />
    Quantity : <select name="itemQty"><option value="1">1</option><option value="2">2</option><option value="3">3</option></select> 
    <input class="dw_button" type="submit" name="submitbutt" value="Buy (225.00 <?php echo $PayPalCurrencyCode; ?>)" />
    </form>
    </td>
  </tr>
</table>

<table class="procut_item" border="0" cellpadding="4">
  <tr>
    <td width="70%"><h4>Nikon COOLPIX</h4>(Nikon Coolpix S9050 26355 digital camera capture vibrant photos up to 12.1 megapixels)</td>
    <td width="30%">
    <form method="post" action="process.php">
	<input type="hidden" name="itemname" value="Nikon COOLPIX" /> 
	<input type="hidden" name="itemnumber" value="20000" /> 
    <input type="hidden" name="itemdesc" value="Nikon Coolpix S9050 26355 digital camera capture vibrant photos up to 12.1 megapixels." /> 
	<input type="hidden" name="itemprice" value="109.99" /> Quantity : <select name="itemQty"><option value="1">1</option><option value="2">2</option><option value="3">3</option></select> 
    <input class="dw_button" type="submit" name="submitbutt" value="Buy (109.99 <?php echo $PayPalCurrencyCode; ?>)" />
    </form></td>
  </tr>
</table>
</div>
</body>
</html>