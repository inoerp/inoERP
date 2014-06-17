<?php
if (preg_match('/(?i)msie [5-9]/', $_SERVER['HTTP_USER_AGENT'])) {
 echo ($_SERVER['HTTP_USER_AGENT']);
 echo "<h2>Sorry! Your browser is outdated and not compatible with this site!!!</h2> "
 . "Please use any modern browsers such as Firefox, Opera, Chrome, IE 10+ ";
 exit;
}
$dont_check_login = true;
?>
<?php
$content_class = true;
$class_names[] = 'content';
?>
<?php include_once("includes/functions/loader.inc"); ?>
<link href="<?php echo HOME_URL; ?>themes/default/index.css" media="all" rel="stylesheet" type="text/css" />
<div id="all_contents">
 <div id="content_header">
	<div class="left">
	 <span class="longHeading">inoERP is an open source web based enterprise management system.
		It’s built using open source technologies and has a wide range of features suitable for running 
		various kind of  businesses.
	 </span>
	</div>
	<div class="right">
	 <div id="animated_block">
		<div class="play_button">
		 <ul class="inRow asperWidth">
			<li class="clickable"><img class="start_play" src="<?php echo HOME_URL; ?>/themes/default/images/playback_start_16.png"></li>
			<li class="clickable"><img class="stop_play" src="<?php echo HOME_URL; ?>/themes/default/images/playback_stop_16.png"></li>
		 </ul>
		</div>
		<div id="animated_content">
		 <div class="content_1">
			<span class="longHeading"> Automated Kanban</span><br>
			Automated kanban is a planning tool which uses the basic idea of kanban i.e. replenishment upon consumption, but it enhances the process by completely automating it. It does not need any manual signal as system keeps the track of demand/supply and auto generates the kanban signal.
			Automated kanban can be used for both external purchasing as well as for internal material movement trough warehouse and production line.
		 </div>
		 <div class="content_2">
			<span class="longHeading"> Total Flexibility Index</span><br>
			Total Flexibility Index is a value between 0 to infinity, which determines the flexibility model of an organization. TFI helps both the internal organization and customers in mid to long term planning. Organizations make their capital investment decisions on the basis of target TFI. 
			Customers can determine the maximum supply they can expect from a supplier on the basis of supplier TFI.
		 </div>
		 <div class="content_3">
			<span class="longHeading"> Super BOM</span><br>
			Super BOM is a consolidated indented bill of material for all the finished goods in a single product family/planning code. Super BOM shows all the important mid-term planning information such as usage, lead times, average daily demand, total on hand, suppliers, ABC Classification, 
			fixed lot multiplier, fixed dyas supply, minimum order quantity, etc.
		 </div>
		</div>
	 </div>
	</div>
	 <div id="process_folw">
	<img src="<?php HOME_URL ?>files/images/end_to_end_process_v1.png" width="670px">
	<div id="module_message">Roll Over your mouse on any picture to view the corresponding functionality.</div>
 </div>
 </div>

 <div id="summary_content">
	<?php
	$content = new content();
	echo $content->showfrontPage_contents(20, 500);
//		 echo page::front_page_summary(6); 
	?>
 </div>
 <div id="content_bottom"></div>
</div>
<div id="process_content" class="hidden">
 <div class="customer">
	<p>Customer is an external/internal organization who buys good, product or service from another organization.&nbsp; inoERP customer module supports all the functionalities required to create/manage &amp; maintain different type of customer relationships&nbsp; .</p>
  <p>You can<br />1.&nbsp;&nbsp;&nbsp; Enter multiple physical addresses as different customer sites for a single customer.<br />2.&nbsp;&nbsp;&nbsp; Assign &amp; Use the same customer in different business units.<br />3.&nbsp;&nbsp;&nbsp; Assign a business purpose for each address. Such as Ship to, Bill to.
	 <a href="content.php?mode=2&content_id=207&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 <a href="demo.inoideas.org/form.php?class_name=ar_customer&mode=9&ar_customer_id=1&ar_customer_site_id=1">View Online Demo .. </a>
 </div>
 <div class="planning">
	<p>inoERP provides different planning methods to suit different needs.
	 <br />1.&nbsp;&nbsp;&nbsp; Material Requirement Planning :
	 <br />MRP is an old, traditional, push based production planning and inventory control system used to 
	 manage manufacturing processes. The biggest drawback of MRP is that it&rsquo;s a push based system 
	 and doesn&rsquo;t quickly respond to demand/supply variations.<br />
	 <br />2.&nbsp;&nbsp;&nbsp; Min Max Planning:<br />Min Max is a very simple but effective material 
	 replenishment method. For each item, you specify minimum and maximum inventory levels in an 
	 organization or subinvntory (subinvntory level MinMax is not yet fully functional).
	 <br />3.&nbsp;&nbsp;&nbsp; Multi-Bin Min Max Planning<br />4.&nbsp;&nbsp;&nbsp; Automated Kanban System</p>
	<a href="content.php?mode=2&content_id=208&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	<a href="demo.inoideas.org/form.php?class_name=fp_mrp_header&mode=9">View Online Demo .. </a>
 </div>
 <div class="inventory">
	<p>Inventory<p>Inventory<p>Inventory<p>Inventory<p>Inventory
	 <a href="content.php?mode=2&content_id=208&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 <a href="demo.inoideas.org/form.php?class_name=org&mode=9">View Online Demo .. </a>
 </div>
 <div class="sales_order">
	<p>Sales Order<p>Sales Order<p>Sales Order<p>Sales Order
	 <a href="content.php?mode=2&content_id=208&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 <a href="demo.inoideas.org/form.php?class_name=sd_so_header&mode=9">View Online Demo .. </a>
 </div>
 <div class="purchasing">
	<p>Purchasing<p>Purchasing<p>Purchasing
	 <a href="content.php?mode=2&content_id=208&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 <a href="demo.inoideas.org/form.php?class_name=po_header&mode=9">View Online Demo .. </a>
 </div>
 <div class="supplier">
	<p>Supplier<p>Supplier<p>Supplier<p>Supplier
	 <a href="content.php?mode=2&content_id=208&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 <a href="demo.inoideas.org/form.php?class_name=supplier&mode=9">View Online Demo .. </a>
 </div>
 <div class="general_ledger">
	<p>general_ledger<p>general_ledger<p>general_ledger
	 <a href="content.php?mode=2&content_id=208&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 <a href="demo.inoideas.org/form.php?class_name=gl_ledger&mode=9">View Online Demo .. </a>
 </div>
 <div class="payable">
	<p>payable<p>payable<p>payable<p>payable
	 <a href="content.php?mode=2&content_id=208&content_type=documentation">Read More .. </a> &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
	 <a href="demo.inoideas.org/form.php?class_name=ap_transaction_header&mode=9">View Online Demo .. </a>
 </div>
</div>
<?php include_template('footer.inc') ?>

<script type="text/javascript">
 $(document).ready(function() {
	
	 //summar list
var maxListCount = 6;
var shownListCount = 0;
 $('ul.summary_list').on('click', '.remove',function() {
 $(this).closest('li').hide();
 shownListCount++;
 maxListCount++;
update_summary_list(maxListCount, shownListCount);
 });
update_summary_list(maxListCount, shownListCount);


	$('#process_folw').on('mousemove', function(e) {
	 var pageCoords = "( " + e.pageX + ", " + e.pageY + " )";
	 var clientCoords = "( " + e.clientX + ", " + e.clientY + " )";
	 if (e.clientX > 348 && e.clientX < 425 && e.clientY > 200 && e.clientY < 250) {
		var content = $('#process_content').find('.customer').html();
		$("#module_message").html(content);
	 } else if (e.clientX > 260 && e.clientX < 405 && e.clientY > 370 && e.clientY < 470) {
		var content = $('#process_content').find('.planning').html();
		$("#module_message").html(content);
	 }
	 else if (e.clientX > 500 && e.clientX < 560 && e.clientY > 370 && e.clientY < 440) {
		var content = $('#process_content').find('.inventory').html();
		$("#module_message").html(content);
	 }
	 else if (e.clientX > 550 && e.clientX < 600 && e.clientY > 300 && e.clientY < 350) {
		var content = $('#process_content').find('.sales_order').html();
		$("#module_message").html(content);
	 } else if (e.clientX > 550 && e.clientX < 600 && e.clientY > 190 && e.clientY < 250) {
		var content = $('#process_content').find('.receviable').html();
		$("#module_message").html(content);
	 }
	 else if (e.clientX > 770 && e.clientX < 820 && e.clientY > 300 && e.clientY < 370) {
		var content = $('#process_content').find('.purchasing').html();
		$("#module_message").html(content);
	 } else if (e.clientX > 850 && e.clientX < 925 && e.clientY > 420 && e.clientY < 475) {
		var content = $('#process_content').find('.supplier').html();
		$("#module_message").html(content);
	 } else if (e.clientX > 790 && e.clientX < 830 && e.clientY > 190 && e.clientY < 273) {
		var content = $('#process_content').find('.general_ledger').html();
		$("#module_message").html(content);
	 }
	 else if (e.clientX > 860 && e.clientX < 903 && e.clientY > 306 && e.clientY < 362) {
		var content = $('#process_content').find('.payable').html();
		$("#module_message").html(content);
	 }
//	$( ".longHeading").text( "( e.clientX, e.clientY ) : " + clientCoords ); 
	});
 });
</script>