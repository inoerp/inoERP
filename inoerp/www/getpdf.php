<?php

include_once(__DIR__ . '/../inoerp_server/includes/basics/basics.inc');
$data = "inoERP Print";
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