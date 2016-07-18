<!DOCTYPE html>
<html>
<head>
  <title>Image_Barcode Class Test</title>
  <style type="text/css">
    body {
        font-family: Verdana;
        font-size: 10pt;
    }
    h1 {
            font-size: 14pt;
    }
    h2 {
            font-size: 12pt;
    }
    .box {
        border: 1px solid rgb(15, 169, 229) ! important; 
        margin: 10px ! important; 
        padding: 10px ! important; 
        font-size: 0.9em ! important;
        font-weight: normal ! important;
        text-decoration: none !  important;
        line-height: 1.5em ! important;
        color: rgb(0, 0, 0) ! important;
        background-color: rgb(231, 244, 252) ! important;
        white-space: normal !  important;
        cursor: pointer ! important;
    }
    .test {
        border: 1px solid;
        margin: 10px ! important;
        padding: 10px ! important; 
    }
  </style>
</head>
<body style="background-color: #FFFFFF;">

<div class="box">
<h1>Image_Barcode2 Class test</h1>
</div>

<div class="test">
<h2>Interleave 2 of 5 (png):</h2>
<img src="barcode_img.php?num=1234567895&type=int25&imgtype=png"
 alt="PNG: 1234567895" title="PNG: 1234567895"/>
</div>

<div class="test">
<h2>Ean13 (png):</h2>
<img
 src="barcode_img.php?num=1234567891231&type=ean13&imgtype=png"
 alt="PNG: 1234567891231" title="PNG: 1234567891231"/>
</div>

<div class="test">
<h2>Ean8 (png):</h2>
<img
 src="barcode_img.php?num=12345670&type=ean8&imgtype=png"
 alt="PNG: 12345670" title="PNG: 12345670"/>
</div>

<div class="test">
<h2>Code39 (png):</h2>
<img
 src="barcode_img.php?num=BARCODE&type=Code39&imgtype=png"
 alt="PNG: BARCODE" title="PNG: BARCODE"/>
</div>

<div class="test">
<h2>UPC-A (png):</h2>
<img
 src="barcode_img.php?num=123456789128&type=upca&imgtype=png"
 alt="PNG: 123456789128" title="PNG: 123456789128"/>
</div>

<div class="test">
<h2>UPC-E (png):</h2>
<img
 src="barcode_img.php?num=01507113&type=upce&imgtype=png"
 alt="PNG: 12345678" title="PNG: 12345678"/>
</div>

<div class="test">
<h2>Code128 (png):</h2>
<img
 src="barcode_img.php?num=barcode&type=code128&imgtype=png"
 alt="PNG: barcode" title="PNG: barcode"/>
</div>

<div class="test">
<h2>PostNet (png):</h2>
<img
 src="barcode_img.php?num=202609900&type=postnet&imgtype=png"
 alt="PNG: 202609900" title="PNG: 202609900"/>
</div>

</body>
</html>