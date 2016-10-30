<div class="row small-left-padding">
<div id="form_all">
 <form  method="post" id="sd_store"  name="sd_store">
  <span class="heading"><?php echo gettext('Physical Store') ?></span>
  <div id ="form_header">
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
     <li><a href="#tabsHeader-2"><?php echo gettext('Accounts') ?></a></li>
     <li><a href="#tabsHeader-3"><?php echo gettext('Address') ?></a></li>
     <li><a href="#tabsHeader-4"><?php echo gettext('Contact') ?></a></li>
     <li><a href="#tabsHeader-5"><?php echo gettext('Attachments') ?></a></li>
     <li><a href="#tabsHeader-6"><?php echo gettext('Notes') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_text_field_dr_withSearch('sd_store_id') ?>
         <a name="show" href="form.php?class_name=sd_store&<?php echo "mode=$mode"; ?>" class="show document_id sd_store_id">
          <i class="fa fa-refresh"></i></a> 
        </li> 
        <li><?php $f->l_text_field_dm('store_name'); ?> </li> 
        <li><?php $f->l_text_field_dm('code'); ?> </li> 
        <li><?php $f->l_text_field_d('type'); ?> </li> 
        <li><?php $f->l_select_field_from_object('org_id', org::find_all_inventory(), 'org_id', 'org', $$class->org_id, 'org_id', '', '', $readonly1); ?></li> 
        <li><?php $f->l_text_field_d('description'); ?> </li> 
        <li><?php $f->l_status_field_d('status'); ?></li>
        <li><label><img src="<?php echo HOME_URL; ?>themes/images/serach.png" class="address_id select_popup clickable">
          <?php echo gettext('Address Id') ?></label><input type="text"  name="address_id[]" value="<?php echo htmlentities($sd_store->address_id);
          ?>" maxlength="50" id="address_id"> 
        </li> 
       </ul> 
      </div>
     </div>
     <div id="tabsHeader-2" class="tabContent">
      <div class="large_shadow_box"> 
       <ul class="column header_field"> 
        <li><?php $f->l_ac_field_d('cogs_ac_id'); ?></li>
        <li><?php $f->l_ac_field_dm('revenue_ac_id'); ?></li>
        <li><?php $f->l_ac_field_dm('cash_ac_id'); ?></li>
        <li><?php $f->l_ac_field_dm('tax_ac_id'); ?></li>
       </ul> 
      </div>
     </div>
     <div id="tabsHeader-3" class="tabContent">
      <ul class="address inline_list">
       <li><?php echo $f->l_text_field('phone', $address->phone, '', '', '', '', 1); ?></li>
       <li><?php echo $f->l_text_field('email', $address->email, '', '', '', '', 1); ?></li>
       <li><?php echo $f->l_text_field('website', $address->website, '', '', '', '', 1); ?></li>
       <li><?php echo $f->l_text_field('country', $address->country, '', '', '', '', 1); ?></li>
       <li><?php echo $f->l_text_field('postal_code', $address->postal_code, '', '', '', '', 1); ?></li>
       <li><label><?php echo gettext('Address') ?></label>  
        <textarea readonly name="address" id="address" cols="22" rows="3" placeholder="<?php echo gettext('Select Address Id')?>"><?php echo trim(htmlentities($address->address)); ?></textarea>
       </li>
      </ul>
     </div>
     <div id="tabsHeader-4" class="tabContent">
      <?php
      if (!empty($all_contacts)) {
       include_once HOME_DIR . '/extensions/contact/view/contact_view_template.php';
      }
      ?>
      <div>
       <ul id="new_contact_reference">
        <li class='new_object1'><label><img class="extn_contact_id select_popup clickable"  src="<?php echo HOME_URL; ?>themes/images/serach.png"/>
          <?php echo gettext('Associate Contact') ?></label>  
         <?php
         echo $f->hidden_field('extn_contact_id_new', '');
         echo $f->text_field('contact_name_new', '', '20', '', 'select_contact');
         ?>  </li>
        <li class='clickable' id='add_new_contact' title='New contact reference field'><i class="fa fa-plus-circle"></i></li>
       </ul>
      </div>
     </div>
     <div id="tabsHeader-5" class="tabContent">
      <div> <?php echo ino_attachement($file) ?> </div>
     </div>
     <div id="tabsHeader-6" class="tabContent">
      <div> 
       <div id="comments">
        <div id="comment_list">
         <?php echo!(empty($comments)) ? $comments : ""; ?>
        </div>
        <div id ="display_comment_form">
         <?php
         $reference_table = 'sd_store';
         $reference_id = $$class->sd_store_id;
         ?>
        </div>
        <div id="new_comment">
        </div>
       </div>
      </div>
     </div>
    </div>
   </div>
  </div>
 </form>
 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Subinventories') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Values') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <form action=""  method="post" id="sd_store_subinventory_line"  name="sd_store_subinventory_line">
     <div id="tabsLine-1" class="tabContent">
      <table class="form_table">
       <thead> 
        <tr>
         <th><?php echo gettext('Action') ?></th>
         <th><?php echo gettext('Line Id') ?></th>
         <th><?php echo gettext('Subinventory') ?>#</th>
         <th><?php echo gettext('Building') ?></th>
         <th><?php echo gettext('Floor') ?></th>
         <th><?php echo gettext('Wing') ?></th>
         <th><?php echo gettext('Description') ?></th>
         <th><?php echo gettext('Status') ?></th>
        </tr>
       </thead>
       <tbody class="form_data_line_tbody sd_store_subinventory_values" >
        <?php
        $count = 0;
        $sd_store_subinventory_object_ai = new ArrayIterator($sd_store_subinventory_object);
        $sd_store_subinventory_object_ai->seek($position);
        while ($sd_store_subinventory_object_ai->valid()) {
         $sd_store_subinventory = $sd_store_subinventory_object_ai->current();
         ?>         
         <tr class="sd_store_subinventory<?php echo $count ?>">
          <td><?php
           echo ino_inline_action($sd_store_subinventory->sd_store_subinventory_id, array('sd_store_id' => $$class->sd_store_id));
           ?>
          </td>
          <td><?php form::number_field_wid2sr('sd_store_subinventory_id'); ?></td>
          <td>
           <?php echo $f->select_field_from_object('subinventory_id', subinventory::find_all_of_org_id($$class->org_id), 'subinventory_id', 'subinventory', $$class_second->subinventory_id, '', 'subinventory_id copyValue', ''); ?>
          </td>
          <td><?php $f->text_field_wid2('floor_number'); ?></td>
          <td><?php $f->text_field_wid2('building_number'); ?></td>
          <td><?php $f->text_field_wid2('wing_number'); ?></td>
          <td><?php $f->text_field_wid2('description'); ?></td>
          <td><?php echo $f->status_field('status'); ?></td>
         </tr>
         <?php
         $sd_store_subinventory_object_ai->next();
         if ($sd_store_subinventory_object_ai->key() == $position + $per_page) {
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
</div>
</div>

<div class="row small-top-margin">
<div id="pagination" style="clear: both;">
 <?php echo $pagination->show_pagination(); ?>
</div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sd_store" ></li>
  <li class="lineClassName" data-lineClassName="sd_store_subinventory" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="primary_column_id" data-primary_column_id="sd_store_id" ></li>
  <li class="form_header_id" data-form_header_id="sd_store" ></li>
  <li class="line_key_field" data-line_key_field="sd_store_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="sd_store_subinventory" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sd_store_id" ></li>
  <li class="docLineId" data-docLineId="sd_store_subinventory_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sd_store" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-docHedaderId="sd_store_subinventory" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="3" ></li>
 </ul>
</div>
