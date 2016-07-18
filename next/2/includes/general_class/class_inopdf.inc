<?php

/*
 * textfields
 * numberfields
 * accounfields
 * textarea
 */

class inopdf extends FPDF {

// Page header
 function Header($font='Arial',$image_path='themes/default/images/excel.png', $tile='inoERP PDF File') {
	// Logo
		$this->Image($image_path, 10, 6, 30);
	// Arial bold 15
	$this->SetFont($font, 'B', 15);
	// Move to the right
	$this->Cell(80);
	// Title
	$this->Cell(30, 10, $tile, 1, 0, 'C');
	// Line break
	$this->Ln(20);
 }

// Page footer
 function Footer($font='Arial', $font_size='8') {
	// Position at 1.5 cm from bottom
	$this->SetY(-15);
	// Arial italic 8
	$this->SetFont($font, 'I', $font_size);
	// Page number
	$this->Cell(0, 10, 'Page ' . $this->PageNo() . '/{nb}', 0, 0, 'C');
 }

}

//end of form class
?>