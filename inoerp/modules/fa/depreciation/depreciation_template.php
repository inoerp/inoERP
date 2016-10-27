<div id="form_all">
 <form  method="post" id="fa_depreciation_header"  name="fa_depreciation_header">
  <span class="heading"><?php echo gettext('Depreciation Header') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Notes') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Actions') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('fa_depreciation_header_id'); ?>
         <a name="show" href="form.php?class_name=fa_depreciation_header&<?php echo "mode=$mode"; ?>" class="show document_id fa_depreciation_header_id">
          <i class='fa fa-refresh'></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('fa_asset_book_id', fa_asset_book::find_all_withFinanceDetails(), 'fa_asset_book_id', 'asset_book_name', $$class->fa_asset_book_id, 'fa_asset_book_id', '', 1, $readonly1, '', '', '', 'ledger_id'); ?></li>
        <li><label><?php echo gettext('Period') ?></label><?php echo $period_stmt; ?> </li>
        <li><?php $f->l_text_field_dm('description'); ?></li>
        <li><?php $f->l_select_field_from_array('status', fa_depreciation_header::$status_a, $$class->status, 'status', '', 1, 1, 1); ?> </li>
        <li><?php $f->l_text_field_dr('gl_journal_header_id', 'always_readonly'); ?></li>
       </ul>

      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'fa_depreciation_header';
         $reference_id = $$class->fa_depreciation_header_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div class="col-sm-offset-1">      <div class="btn-group row">
        <button type="button" class="btn btn-primary">
         <span  aria-hidden="true"></span><i class='fa fa-tasks'></i> <?php echo gettext('Actions') ?></button>
        <button type="button" class="btn btn-primary dropdown-toggle" data-toggle="dropdown" aria-expanded="false">
         <span class="caret"></span>
         <span class="sr-only"><?php echo gettext('Toggle Dropdown')?></span>
        </button>
        <ul class="dropdown-menu" role="menu">
         <li><a href="<?php echo HOME_URL; ?>program.php?class_name=fa_depreciation_header&program_name=prg_run_depreciation">
           <?php echo gettext('Run Depreciation') ?></a></li>
         <!--<li><a href="#"><?php // echo gettext('Confirm Depreciation')  ?></a></li>-->
         <li><a id="post_depreciation" href="#"><?php echo gettext('Post Depreciation') ?></a></li>
         <li><?php echo $f->hidden_field_withId('action', '') ?></li>
        </ul>
       </div></div>

     </div>
    </div>
   </div>
  </div>
 </form>

 <?php
 if (!empty($$class->fa_depreciation_header_id)) {
  require_once __DIR__ . '/line/line_template.php';
 } else {
  echo ' <div id="form_line">  <div class="alert alert-danger" role="alert">
  <h1>Save the header record and run the depreciation program to view line details </h1>
  </div></div>';
 }
 ?>
</div>


<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_depreciation_header" ></li>
  <li class="lineClassName" data-lineClassName="fa_depreciation_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_depreciation_header_id" ></li>
  <li class="form_header_id" data-form_header_id="fa_depreciation_header" ></li>
  <li class="line_key_field" data-line_key_field="line_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fa_depreciation_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_depreciation_header_id" ></li>
  <li class="docLineId" data-docLineId="fa_depreciation_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_depreciation_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="fa_depreciation_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
