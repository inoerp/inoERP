<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @component code https://github.com/inoerp/inoERP
-->

<div id ="form_header"><span class="heading"><?php echo gettext('Asset Component') ?></span>
 <div id="tabsHeader">
  <ul class="tabMain">
   <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
   <li><a href="#tabsHeader-2"><?php echo gettext('Attachments') ?></a></li>
   <li><a href="#tabsHeader-3"><?php echo gettext('Note') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <div id="tabsHeader-1" class="tabContent">
    <ul class="column header_field">
     <li><label><?php echo gettext('Asset Number') ?></label>
      <?php
      echo $f->val_field('asset_number', $fa_asset->asset_number, '', 'asset_number', '', '', '', 'fa_asset', 'asset_number');
      echo $f->hidden_field_withIdClass('fa_asset_id', $fa_asset->fa_asset_id, 'fa_asset_id');
      ?>
      <i class="generic g_select_asset_number select_popup clickable fa fa-search" data-class_name="fa_asset"></i>
      <a name="show" href="form.php?class_name=fa_asset_component&<?php echo "mode=$mode"; ?>" class="show document_id fa_asset_id">
       <i class="fa fa-refresh"></i></a> 
     </li>
     <li><label><?php echo gettext('Asset Type') ?></label><?php echo $f->text_field('type', $fa_asset->type, '', 'type', '', '', 1); ?></li>
     <li><label><?php echo gettext('Description') ?></label><?php echo $f->text_field('description', $fa_asset->description, '', 'description', '', '', 1); ?></li>
     <li><label><?php echo gettext('Status') ?></label><?php echo $f->text_field('status', $fa_asset->status, '', 'status', '', '', 1); ?></li>
    </ul>
   </div>
   <div id="tabsHeader-2" class="tabContent">
    <div> <?php echo ino_attachement($file) ?> </div>
   </div>
   <div id="tabsHeader-3" class="tabContent">
    <div id="comments">
     <div id="comment_list">
      <?php echo!(empty($comments)) ? $comments : ""; ?>
     </div>
     <div id ="display_comment_form">
      <?php
      $reference_table = 'fa_asset';
      $reference_id = $fa_asset->fa_asset_id;
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
<div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Component Details') ?></span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1"><?php echo gettext('Operation') ?></a></li>
   <li><a href="#tabsLine-2"><?php echo gettext('Future') ?></a></li>
  </ul>
  <div class="tabContainer"> 
   <form method="post" id="fa_asset_component"  name="fa_asset_component">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_line_data_table">
      <thead> 
       <tr>
        <th><?php echo gettext('Action') ?></th>
        <th><?php echo gettext('Asset component Id') ?></th>
        <th><?php echo gettext('Line') ?> #</th>
        <th><?php echo gettext('Asset') ?> #</th>
        <th><?php echo gettext('Asset Description') ?></th>
        <th><?php echo gettext('Component Type') ?></th>
        <th><?php echo gettext('Source Type') ?></th>
        <th><?php echo gettext('Description') ?></th>
        <th><?php echo gettext('Reference1') ?></th>
        <th><?php echo gettext('Reference2') ?></th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody fa_asset_component_line_values" >
       <?php
       $detailCount = 0;
       foreach ($fa_asset_component_object as $fa_asset_component) {
        if (!empty($fa_asset_component->component_asset_id)) {
         $comp_asset = new fa_asset();
         $comp_asset->findBy_id($fa_asset_component->component_asset_id);
//         pa($comp_asset);
         $fa_asset_component->component_asset_number = $comp_asset->asset_number;
         $fa_asset_component->component_asset_description = $comp_asset->description;
        } else {
         $fa_asset_component->component_asset_number = $fa_asset_component->component_asset_description = null;
        }
        ?>
        <tr class="fa_asset_component<?php echo $detailCount ?>">
         <td>
          <?php
          echo ino_inline_action($fa_asset_component->fa_asset_component_id, array('fa_asset_id' => $fa_asset->fa_asset_id));
          ?>
         </td>
         <td><?php $f->text_field_widr('fa_asset_component_id', 'always_readonly') ?></td>
         <td><?php $f->text_field_wids('line_number') ?></td>
         <td><?php
         echo $f->val_field_wid('component_asset_number', 'fa_asset', 'asset_number','','');
         echo $f->hidden_field_withCLass('component_asset_id', $fa_asset_component->component_asset_id, 'fa_asset_id');
          ?>
          <i class="generic g_select_asset_number select_popup clickable fa fa-search" data-class_name="fa_asset"></i>
         </td>
         <td><?php $f->text_field_wid('component_asset_description') ?></td>
         <td><?php $f->text_field_wid('component_type') ?></td>
         <td><?php $f->text_field_wid('source_type') ?></td>
         <td><?php $f->text_field_wid('description') ?></td>
         <td><?php $f->text_field_wid('reference1') ?></td>
         <td><?php $f->text_field_wid('reference2') ?></td>
        </tr>
        <?php
        $detailCount++;
       }
       ?>

      </tbody>
     </table>


    </div> 
    <!--end of tab1-->
    <div id="tabsLine-2" class="tabContent">
     <div class="first_rowset"> 
      <ul class="column five_column"> 
      </ul>
     </div>
     <div class="second_rowset">

     </div> 
     <!--                end of tab2 div three_column-->
    </div>
   </form>
  </div>
 </div>
</div> 


<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="fa_asset_component" ></li>
  <li class="lineClassName" data-lineClassName="fa_asset_component" ></li>
  <li class="line_key_field" data-line_key_field="name" ></li>
  <li class="primary_column_id" data-primary_column_id="fa_asset_id" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="fa_asset_component" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="fa_asset_component_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="fa_asset_component" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>