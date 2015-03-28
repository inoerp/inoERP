<form action=""  method="post" id="ec_product"  name="ec_product"><span class="heading">eCommerce Product </span>
 <div id ="form_header"><?php $f = new inoform() ?>
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    <li><a href="#tabsHeader-2"><?php echo gettext('Images') ?></a></li>
    <li><a href="#tabsHeader-3"><?php echo gettext('Product Description') ?></a></li>
    <li><a href="#tabsHeader-4"><?php echo gettext('Attachments') ?></a></li>
    <li><a href="#tabsHeader-5"><?php echo gettext('Note') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <ul class="column header_field">
      <li><?php $f->l_text_field_dr_withSearch('ec_product_id') ?>
       <a name="show" href="form.php?class_name=ec_product&<?php echo "mode=$mode"; ?>" class="show document_id ec_product_id"><i class="fa fa-refresh"></i></a> 
      </li>
      <li><?php $f->l_select_field_from_object('org_id', $org->findAll_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', 1, $readonly1); ?></li>
      <li><?php $f->l_text_field_dm('product_name'); ?></li>
      <li><label><i class="select_item_number select_popup clickable fa fa-search"></i>
        <?php echo gettext('Inv Item Number') ?></label><?php
       echo $f->hidden_field_withId('item_id_m', $$class->item_id_m);
       $f->text_field_dm('item_number', 'select_item_number');
       ?>
      </li>
      <li><?php $f->l_select_field_from_object('tax_code_id', mdm_tax_code::find_all_outTax_by_inv_org_id($$class->org_id), 'mdm_tax_code_id', 'tax_code', $$class->tax_code_id, '', 'input_tax medium', '', $readonly, '', '', '', 'percentage') ?></li>
      <li><?php $f->l_select_field_from_object('price_list_id', mdm_price_list_header::find_all_purchasing_pl(), 'mdm_price_list_header_id', 'price_list', $$class->price_list_id); ?></li>
      <li><?php $f->l_date_fieldAnyDay('new_date_trom', $$class->new_date_trom) ?></li>
      <li><?php $f->l_date_fieldAnyDay('new_date_to', $$class->new_date_to) ?></li>
      <li><?php $f->l_select_field_from_array('status', ec_product::$status_a, $$class->status, 'status', '', 1); ?>        </li>
      <li><?php $f->l_select_field_from_array('visibility', ec_product::$visibility_a, $$class->visibility, 'visibility', ''); ?>        </li>
     </ul>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div class="large_shadow_box"> 
      <div> <?php echo extn_image::ino_images($class, $$class->ec_product_id) ?> </div>
     </div>
    </div>
    <div id="tabsHeader-3" class="tabContent">
     <ul class="column two_column">
      <li><label><?php echo gettext('Meta Title') ?></label><?php echo form::text_area('meta_title', $$class->meta_title, '2', '50', '', 'Maximum 255 Characters'); ?>      </li>
      <li><label><?php echo gettext('Meta Keywords') ?></label><?php echo form::text_area('meta_keywords', $$class->meta_keywords, '2', '50', '', 'Maximum 255 Characters'); ?>      </li>
      <li><label><?php echo gettext('Meta Description') ?></label><?php echo form::text_area('meta_title', $$class->meta_description, '2', '50', '', 'Maximum 255 Characters'); ?>      </li>
     </ul>
     <ul class="column one_column">
      <li><label><?php echo gettext('Product Description') ?></label><?php echo form::text_area('product_description', $$class->product_description, '6', '120', '', 'No Character Limits'); ?>      </li>
     </ul>
    </div>
    <div id="tabsHeader-4" class="tabContent">
     <div> <?php echo ino_attachement($file) ?> </div>
    </div>
    <div id="tabsHeader-5" class="tabContent">
     <div id="comments">
      <div id="comment_list">
       <?php echo!(empty($comments)) ? $comments : ""; ?>
      </div>
      <div id ="display_comment_form">
       <?php
       $reference_table = 'ec_product';
       $reference_id = $$class->ec_product_id;
       ?>
      </div>
      <div id="new_comment">
      </div>
     </div>
     <div> 
     </div>
    </div>
   </div>
  </div>
 </div>
 <div id ="form_line" class="form_line"><span class="heading"> Product Details </span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Categories') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Catalogs') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Related Products') ?></a></li>
    <li><a href="#tabsLine-4"><?php echo gettext('Stores & Sites') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <div class="category-div">
      <span class="heading"><?php echo gettext('Categories'); ?></span>
      <div class="existing-category"><?php echo!empty($category) ? category::category_stmt($category) : ''; ?></div>
      <div class="add-category"><?php echo $categoriey_select_option; ?></div>
     </div>
     <!--end of tab1 div three_column-->
    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">

     <!--                end of tab2 div three_column-->
    </div>
    <!--end of tab2 (purchasing)!!!! start of sales tab-->
    <div id="tabsLine-3" class="tabContent">

    </div> 
   </div>


  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="ec_product" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="ec_product_id" ></li>
  <li class="form_header_id" data-form_header_id="ec_product" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="ec_product_id" ></li>
  <li class="btn1DivId" data-btn1DivId="ec_product" ></li>
 </ul>
</div>