<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
 -->
<div id="po_divId">
 <!--    START OF FORM HEADER-->

 <!--    End of place for showing error messages-->

 <div id ="form_header">
  <span class="heading"><?php echo gettext('Custom Template for ADMIN') ?></span>
  <form action=""  method="post" id="po_header"  name="po_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Finance') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Address Details') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Note') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-6"><?php echo gettext('Actions') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
       <ul class="column header_field">
        <li><?php $f->l_text_field_dr_withSearch('po_header_id') ?>
         <a name="show" href="form.php?class_name=po_header&<?php echo "mode=$mode"; ?>" class="show document_id po_header_id"><i class="fa fa-refresh"></i></a> 
        </li>
        <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $$class->bu_org_id, 'bu_org_id', '', 1, $readonly1); ?>        </li>
        <li><?php $f->l_select_field_from_array('po_type', po_header::$po_type_a, $$class->po_type, 'po_type', '', 1, $readonly1, $readonly1); ?>        </li>
        <li><?php $f->l_text_field_d('po_number', 'primary_column2'); ?> </li>
        <li><?php $f->l_text_field_d('release_number'); ?></li>
        <li><?php $f->l_select_field_from_object('status', po_header::po_status(), 'option_line_code', 'option_line_value', $$class->po_status, 'po_status', 'dont_copy', '', 1); ?></li>
        <li><?php echo $f->hidden_field_withId('ref_po_header_id', $$class->ref_po_header_id); ?>
         <?php echo $f->hidden_field_withId('supplier_id', $$class->supplier_id); ?>
         <label class="auto_complete"><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="supplier_id select_popup clickable">
          <?php echo gettext('Supplier Name') ?></label><?php echo $f->text_field('supplier_name', $$class->supplier_name, '20', 'supplier_name', 'select_supplier_name', 1, $readonly1); ?> </li>
        <li><?php $f->l_text_field_d('supplier_number'); ?></li>
        <li><label><?php echo gettext('Supplier Site') ?></label><?php
         $supplier_site_obj = !empty($$class->supplier_id) ? supplier_site::find_by_parent_id($$class->supplier_id) : array();
         echo $f->select_field_from_object('supplier_site_id', $supplier_site_obj, 'supplier_site_id', 'supplier_site_name', $$class->supplier_site_id, 'supplier_site_id', '', '', $readonly1);
         ?> </li>
        <li><?php $f->l_text_field_d('rev_number'); ?></li> 
        <li><?php $f->l_checkBox_field_d('multi_bu_cb'); ?></li> 
        <li><?php $f->l_text_field_d('buyer'); ?></li> 
        <li><?php $f->l_text_field_d('description'); ?></li> 
       </ul>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><?php $f->l_date_fieldFromToday('agreement_start_date', $$class->agreement_start_date) ?></li>
        <li><?php $f->l_date_fieldFromToday('agreement_end_date', $$class->agreement_start_date) ?></li>
        <li><?php $f->l_select_field_from_object('doc_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->doc_currency, 'doc_currency', '', 1, $readonly); ?></li>
        <li><?php $f->l_select_field_from_object('currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->currency, 'currency', '', 1, 1); ?></li>
        <li><?php $f->l_select_field_from_object('exchange_rate_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_code', $$class->exchange_rate_type, 'exchange_rate_type', '', 1, $readonly); ?></li>
        <li><?php $f->l_number_field('exchange_rate', $$class->exchange_rate, '', 'exchange_rate'); ?> </li>
        <li><?php $f->l_select_field_from_object('price_list_header_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_header_id); ?></li>
        <li><?php $f->l_number_field('header_amount', $$class->header_amount, '15', 'header_amount'); ?></li>
        <li><?php $f->l_number_field('tax_amount', $$class->tax_amount, '15', 'tax_amount'); ?></li>
        <li><?php $f->l_select_field_from_object('payment_term_id', payment_term::find_all(), 'payment_term_id', 'payment_term', $$class->payment_term_id, 'payment_term_id', '', 1, $readonly1); ?></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <div class="left_half shipto address_details">
       <ul class="column four_column">
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
          <?php gettext('Ship To Site Id'); ?></label><?php $f->text_field_d('ship_to_id', 'address_id site_address_id'); ?>
        </li>
        <li><?php $f->l_text_field_dr('ship_to_address_name', 'address_name'); ?></li>
        <li><?php $f->l_text_field_dr('ship_to_address', 'address'); ?></li>
        <li><?php $f->l_text_field_dr('ship_to_country', 'country'); ?></li>
        <li><?php echo $f->l_text_field_dr('ship_to_postal_code', 'postal_code'); ?></li>
       </ul>
      </div> 
      <div class="right_half billto address_details">
       <ul class="column four_column">
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
          <?php gettext('Bill To Site Id'); ?></label>
         <?php $f->text_field_d('bill_to_id', 'address_id  site_address_id'); ?>
        </li>
        <li><?php $f->l_text_field_dr('bill_to_address_name', 'address_name'); ?></li>
        <li><?php $f->l_text_field_dr('bill_to_address', 'address'); ?></li>
        <li><?php $f->l_text_field_dr('bill_to_country', 'country'); ?></li>
        <li><?php echo $f->l_text_field_dr('bill_to_postal_code', 'postal_code'); ?></li>
       </ul>
      </div> 
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <div id="comments">
       <div id="comment_list">
        <?php echo!(empty($comments)) ? $comments : ""; ?>
       </div>
       <div id ="display_comment_form">
        <?php
        $reference_table = 'po_header';
        $reference_id = $$class->po_header_id;
        ?>
       </div>
       <div id="new_comment">
       </div>
      </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-6" class="tabContent">
      <div> 
       <ul class="column four_column">
        <li id="document_print"><label><?php echo gettext('Document Print') ?></label>
         <a class="button" target="_blank"
            href="<?php echo HOME_URL ?>modules/po/po_print.php?po_header_id=<?php echo!(empty($$class->po_header_id)) ? $$class->po_header_id : ""; ?>" ><?php echo gettext('Print PO') ?></a>
        </li>
        <li><label><?php echo gettext('Action') ?></label>
         <?php
         echo $f->select_field_from_array('action', $$class->action_a, '', 'action', '', '', $readonly, $action_readonly)
         ?>
        </li>
       </ul>

       <div id="comment" class="shoe_comments">
       </div>
      </div>
     </div>
    </div>

   </div>
  </form>
 </div>
 <?php
 if ($$class->po_type == 'CONTRACT') {
  echo '</div></div>  </div>     <div id="content_bottom"></div>   </div>   <div id="content_right_right"></div>  </div> </div>';
  include_template('footer.inc');
  return;
 }
 ?>

 <!--END OF FORM HEADER-->
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="po_header" ></li>
  <li class="lineClassName" data-lineClassName="po_line" ></li>
  <li class="detailClassName" data-detailClassName="po_detail" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="po_header_id" ></li>
  <li class="form_header_id" data-form_header_id="po_header" ></li>
  <li class="line_key_field" data-line_key_field="item_description" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <!--<li class="single_line" data-enable_select="true" ></li>-->
  <li class="form_line_id" data-form_line_id="po_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="po_header_id" ></li>
  <li class="docLineId" data-docLineId="po_line_id" ></li>
  <li class="docDetailId" data-docDetailId="po_detail_id" ></li>
  <li class="btn1DivId" data-btn1DivId="po_header" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="po_line" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="4" ></li>
 </ul>
</div>
