<div id ="form_header">
 <span class="heading"><?php echo gettext('Asset Transactions') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Other Details') ?></a></li>
  </ul>
  <div class="tabContainer">
   <div id="tabsHeader-1" class="tabContent">
    <div class="large_shadow_box"> 
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('fa_asset_transaction_id') ?>
       <a name="show" href="form.php?class_name=fa_asset_transaction_v&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_transaction_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php
       echo $f->l_val_field_dm('asset_number', 'fa_asset', 'asset_number', '', 'asset_number', 'vf_select_asset_number');
       echo $f->hidden_field_withId('fa_asset_id', $$class->fa_asset_id);
       ?><i class="generic g_select_asset_number select_popup clickable fa fa-search" data-class_name="fa_asset"></i>
       <a name="show3" href="form.php?class_name=fa_asset_transaction_v&<?php echo "mode=$mode"; ?>" class="show3 action document_id fa_asset_transaction_v_with_assetid"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_text_field_dr('tag_number'); ?></li>
      <li><?php $f->l_text_field_dr('serial_number'); ?></li>
      <li><?php $f->l_text_field_dr('key_number'); ?></li>
      <li><?php $f->l_text_field_dr('asset_description'); ?></li>
      <li><?php $f->l_text_field_dr('asset_book_name'); ?></li>
      <li><?php $f->l_text_field_dr('type'); ?></li>
      <li><?php $f->l_text_field_dr('book_description'); ?></li>
     </ul>
    </div>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div class="large_shadow_box"> 
     <div>
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr('fa_asset_id'); ?></li>
       <li><?php $f->l_text_field_dr('fa_asset_book_info_id'); ?></li>
       <li><?php $f->l_text_field_dr('fa_asset_book_id'); ?></li>
      </ul>
     </div>

    </div>
   </div>
  </div>
 </div>

</div>

<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Transaction Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Info-1') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form  method="post" id="fa_asset_transaction_entries_line"  name="fa_asset_transaction_entries_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Seq') ?></th>
        <th><?php echo gettext('Transaction Type') ?></th>
        <th><?php echo gettext('Quantity') ?></th>
        <th><?php echo gettext('Amount') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Journal Header Id') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody fa_asset_transaction_entries_values" >
       <?php
       $f = new inoform();
       $count = 0;
       $fa_asset_transaction_object_ai = new ArrayIterator($fa_asset_transaction_object);
       $fa_asset_transaction_object_ai->seek($position);
       while ($fa_asset_transaction_object_ai->valid()) {
        $fa_asset_transaction_v = $fa_asset_transaction_object_ai->current();
        ?>         
        <tr class="fa_asset_transaction_entries<?php echo $count ?>">
         <td><?php $f->seq_field_d($count); ?></td>
         <td><?php $f->text_field_widr('transaction_type'); ?></td>
         <td><?php $f->text_field_widr('quantity'); ?></td>
         <td><?php $f->text_field_widr('amout'); ?></td>
         <td><?php $f->text_field_widr('description'); ?></td>
         <td><?php $f->text_field_widr('gl_journal_header_id'); ?></td>
        </tr>
        <?php
        $fa_asset_transaction_object_ai->next();
        if ($fa_asset_transaction_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
   </form>
  </div>

 </div>
</div> 

<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="fa_asset_transaction_id" ></li>

 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="fa_asset_transaction_id" ></li>
  <li class="btn1DivId" data-btn1DivId="fa_asset_transaction" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>