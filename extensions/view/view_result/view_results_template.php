<?php require_once 'view_result.inc'?>
<div id="all_contents">
 <div id="content_left"></div>
<div id="content_right">
 <div id="content_right_left">
  <div id="content_top"></div>
<div id="content">
   <div id="main">

    <div id="structure">
     <div id="contents">
      <div id ="form_header">
       <ul id="form_box"> 
        <li>
         <div id="loading"><img alt="Loading..." src="<?php echo HOME_URL; ?>themes/images/loading.gif"/></div>
        </li>
        <li> 
         <div class="error"></div>
         <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
        </li>
				<li>
				 <div class="filters">
					<?php echo !(empty($view_filter_statement))? $view_filter_statement : ""; ?>
				 </div>
				</li>
				
        
       </ul>
      </div>
			<div id="view_results"><?php echo !(empty($view_result))? $view_result : ""; ?> </div>
     </div>
    </div>
   </div>
</div>
  <div id="content_bottom"></div>
 </div>
 <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>
