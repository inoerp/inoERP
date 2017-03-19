<?php
require_once 'includes/basics/basics.inc';
$data = "Hello World India of skds skdssd ";
$pdf = new inopdf();
$pdf->AliasNbPages();
$pdf->AddPage();
$pdf->SetFont('Times', '', 12);
//for ($i = 1; $i <= 40; $i++)
$name = "data_pdf_" . date("Y-m-d");
 $pdf->Cell(0, 10, $data, 0, 1);
 $pdf->Line(10, -10, -20, -20);
$pdf->Output($name,'D');
?>
