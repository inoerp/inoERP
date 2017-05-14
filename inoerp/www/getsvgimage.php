<?php

 include_once(__DIR__ . '/../inoerp_server/includes/basics/basics.inc');
$svgimage = new getsvgimage();
$chart_name = 'PO Analysis';
$chart_type = 'horizonatl_bar';
$chart_width = '720';
$chart_height = '450';
$data = [
		array('label' => 'standrad po', 'value' => '300'),
		array('label' => 'blanket po', 'value' => '100'),
		array('label' => 'planned po', 'value' => '70'),
		array('label' => 'contrat po', 'value' => '190'),
		array('label' => 'xcontrat po', 'value' => '450'),
		array('label' => 'efdfcontrat po', 'value' => '1200'),
];
$svgimage->setProperty('_chart_name', $chart_name);
$svgimage->setProperty('_chart_width', $chart_width);
$svgimage->setProperty('_chart_height', $chart_height);
$svgimage->setProperty('_chart_type', $chart_type);
$svgimage->setProperty('_data', $data);
$chart_image1 = $svgimage->draw_chart();

$svgimage1 = new getsvgimage();
$data2 = [
		array('label' => 'standrad po', 'value' => array('300', '250', '1228','340', '150', '128','1300', '20', '1228' )),
		array('label' => 'blanket po', 'value' => array('23', '111', '345', '250', '1228','340', '250', '1228','340', )),
		array('label' => 'planned po', 'value' => array('343', '78', '900','23', '111', '345','23', '111', '345' )),
];
$legend = ['Q1-2014', 'Q2-2014', 'Q3-2014', 'Q4-2013', 'Q1-2014', 'Q2-2014', 'Q3-2014', 'Q4-2014', 'Q1-2015'];
$svgimage1->setProperty('_chart_name', $chart_name);
$svgimage1->setProperty('_chart_width', $chart_width);
$svgimage1->setProperty('_chart_height', $chart_height);
$svgimage1->setProperty('_chart_type', 'clustered_bar');
$svgimage1->setProperty('_legend', $legend);
$svgimage1->setProperty('_data', $data2);
$chart_image2 = $svgimage1->draw_chart();

$svgimage3 = new getsvgimage();
$svgimage3->setProperty('_chart_name', $chart_name);
$svgimage3->setProperty('_chart_width', $chart_width);
$svgimage3->setProperty('_chart_height', $chart_height);
$svgimage3->setProperty('_chart_type', 'stacked_bar');
$svgimage3->setProperty('_legend', $legend);
$svgimage3->setProperty('_data', $data2);
$chart_image3 = $svgimage3->draw_chart();


$svgimage4= new getsvgimage();
$data4 = [
		array('label' => 'standrad po', 'value' => '300'),
		array('label' => 'blanket po', 'value' => '100'),
		array('label' => 'planned po', 'value' => '70'),
		array('label' => 'contrat po', 'value' => '190'),
		array('label' => 'xcontrat po', 'value' => '450'),
		array('label' => 'efdfcontrat po', 'value' => '1200'),
];
$svgimage4->setProperty('_chart_name', $chart_name);
$svgimage4->setProperty('_chart_width', $chart_width);
$svgimage4->setProperty('_chart_height', $chart_height);
$svgimage4->setProperty('_chart_type', 'vertical_column');
$svgimage4->setProperty('_data', $data4);
$chart_image4 = $svgimage4->draw_chart();

$svgimage5 = new getsvgimage();
$svgimage5->setProperty('_chart_name', $chart_name);
$svgimage5->setProperty('_chart_width', $chart_width);
$svgimage5->setProperty('_chart_height', $chart_height);
$svgimage5->setProperty('_chart_type', 'clustered_column');
$svgimage5->setProperty('_legend', $legend);
$svgimage5->setProperty('_data', $data2);
$chart_image5 = $svgimage5->draw_chart();

$svgimage6 = new getsvgimage();
$svgimage6->setProperty('_chart_name', $chart_name);
$svgimage6->setProperty('_chart_width', $chart_width);
$svgimage6->setProperty('_chart_height', $chart_height);
$svgimage6->setProperty('_chart_type', 'stacked_column');
$svgimage6->setProperty('_legend', $legend);
$svgimage6->setProperty('_data', $data2);
$chart_image6 = $svgimage6->draw_chart();

$data3 = ['open po' => '10', 'open pr' => '30', 'open ir' => '7', 'onhand' => '60', 
				 'onhand3' => '40',  'onhand2' => '60'];
$svgimage7 = new getsvgimage();
$svgimage7->setProperty('_chart_name', $chart_name);
$svgimage7->setProperty('_chart_width', $chart_width);
$svgimage7->setProperty('_chart_height', $chart_height);
$svgimage7->setProperty('_chart_type', 'pie');
$svgimage7->setProperty('_data', $data3);
$chart_image7 = $svgimage7->draw_chart();

$svgimage8 = new getsvgimage();
$svgimage8->setProperty('_chart_name', $chart_name);
$svgimage8->setProperty('_chart_width', $chart_width);
$svgimage8->setProperty('_chart_height', $chart_height);
$svgimage8->setProperty('_chart_type', 'donut');
$svgimage8->setProperty('_data', $data3);
$chart_image8 = $svgimage8->draw_chart();

$svgimage9 = new getsvgimage();
$data2 = [
		array('label' => 'standrad po', 'value' => array('300', '250', '1228','340', '150', '128','1300', '20', '1228' )),
		array('label' => 'blanket po', 'value' => array('23', '111', '345', '250', '1228','340', '250', '1228','340', )),
		array('label' => 'planned po', 'value' => array('343', '78', '900','23', '111', '345','23', '111', '345' )),
];

$data5 = ['Opportunity' => '80', 'Leads' => '190', 'Quotes' => '70', 'Sales' => '40'];

$svgimage10 = new getsvgimage();
$svgimage10->setProperty('_chart_name', $chart_name);
$svgimage10->setProperty('_chart_width', $chart_width);
$svgimage10->setProperty('_chart_height', $chart_height);
$svgimage10->setProperty('_chart_type', 'funnel');
$svgimage10->setProperty('_bottom_margin', '30');
$svgimage10->setProperty('_data', $data5);
$chart_image10 = $svgimage10->draw_chart();

$svgimage9->setProperty('_chart_name', $chart_name);
$svgimage9->setProperty('_chart_width', $chart_width);
$svgimage9->setProperty('_chart_height', $chart_height);
$svgimage9->setProperty('_chart_type', 'line');
$svgimage9->setProperty('_legend', $legend);
$svgimage9->setProperty('_data', $data2);
$chart_image9 = $svgimage9->draw_chart();



require_once(INC_BASICS . DS . "getsvgimage_template.inc");
?>

