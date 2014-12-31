<div id ="form_header"><span class="heading">Category Header </span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1">Basic Info</a></li>
   <li><a href="#tabsHeader-2">Future</a></li>
  </ul>
  <div class="tabContainer">
   <form action=""  method="post" id="category"  name="category">
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column three_column">
       <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="category_id select_popup clickable">
         Category Id </label><?php echo form::text_field_dsr('category_id'); ?>
        <a name="show" href="form.php?class_name=category&<?php echo "mode=$mode"; ?>" class="show document_id category_id"><img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
       </li>
       <li><label>Primary </label><?php echo $f->checkBox_field_d('primary_cb'); ?>
       </li>
       <li><label>Parent Name :</label> 
        <?php $cat = new category();
        echo $cat->all_child_category_select_option('parent_id', '', $$class->parent_id, 'parent_id', false)
        ?> 
       </li>
       <li><label>Category </label><?php echo $f->text_field('category', $$class->category, '30	 '); ?></li>
       <li><label>Description </label><?php echo $f->text_field('description', $$class->description, '80'); ?></li>
      </ul>
     </div>
    </div>
    <div id="tabsHeader-2" class="tabContent">
     <div> 
      <div id="show_attachment" class="show_attachment">
      </div>
     </div>
    </div>
   </form>		
  </div>
 </div>

</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="category" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="category_id" ></li>
  <li class="form_header_id" data-form_header_id="category" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="category_id" ></li>
  <li class="btn1DivId" data-btn1DivId="category_id" ></li>
 </ul>
</div>