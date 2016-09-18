<!-- * 
inoERP
 *
 * @copyright   2014 Nishit R. Das
 * @license     https://www.mozilla.org/MPL/2.0/
 * @link        http://inoideas.org
 * @source code https://github.com/inoerp/inoERP
-->
<div id="form_all">
 <div id="form_headerDiv">
  <form   method="post" id="po_asl_document"  name="po_asl_document">
   <span class="heading"><?php echo gettext('ASL Basic Info') ?></span>
   <div id="tabsHeader">
    <ul class="tabMain">
     <li><a href="#tabsHeader-1"><?php echo gettext('Basic Info') ?></a></li>
    </ul>
    <div class="tabContainer">
     <div id="tabsHeader-1" class="tabContent">
      <ul class="column header_field">
       <li><label><i class="po_asl_line_id select_popup clickable fa fa-search"></i>
         <?php echo gettext('ASL Line Id') ?></label>
        <?php echo $f->text_field('po_asl_line_id', $po_asl_line_id_h, '', 'po_asl_line_id'); ?>
        <a name="show" href="form.php?class_name=po_asl_document&<?php echo "mode=$mode"; ?>" class="show document_id po_asl_document_id">
         <i class='fa fa-refresh'/></i></a> 
       </li>
       <li><?php $f->l_select_field_from_object('bu_org_id', org::find_all_business(), 'org_id', 'org', $bu_org_id, 'bu_org_id', '', 1, 1); ?>       </li>
       <li><label><?php echo gettext('Supplier Name') ?></label>  
        <?php
        echo $f->text_field('supplier_name', $supplier_name);
        echo $f->hidden_field_withId('supplier_id', $supplier_id)
        ?>   </li>
       <li><label><?php echo gettext('Supplier Site Name') ?></label><?php
        echo $f->text_field('supplier_site_name', $supplier_site_name);
        echo $f->hidden_field_withId('supplier_site_id', $supplier_site_id)
        ?>   </li>  
       <li><label><?php echo gettext('Item Number') ?></label> 
        <?php
        echo $f->text_field('item_number', $item_number);
        echo $f->hidden_field_withId('item_id_m', $item_id_m)
        ?>   </li>  
      </ul>
     </div>
    </div>

   </div>
   <div id="tabsLine">
    <div id ="form_line" class="po_asl_document"><span class="heading"><?php echo gettext('ASL Documents') ?></span>
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Finance') ?> </a></li>      
     </ul>
     <div class="tabContainer"> 
      <div id="tabsLine-1" class="tabContent">
       <table class="form_table">
        <thead> 
         <tr>
          <th><?php echo gettext('Action') ?></th>
          <th><?php echo gettext('Seq') ?>#</th>
          <th><?php echo gettext('Line Id') ?></th>
          <th><?php echo gettext('Document Type') ?>#</th>
          <th><?php echo gettext('Document Number') ?></th>
          <th><?php echo gettext('Start Date') ?></th>
          <th><?php echo gettext('End Date') ?></th>
          <th><?php echo gettext('Priority') ?></th>
         </tr>
        </thead>
        <tbody class="form_data_line_tbody asl_document_values" >
         <?php
         $count = 0;
         foreach ($asl_document_object as $po_asl_document) {
          ?>         
          <tr class="po_asl_document<?php echo $count ?>">
           <td>
            <?php
            echo ino_inline_action($$class->po_asl_document_id, array('po_asl_line_id' => $po_asl_line_id_h));
            ?>
           </td>
           <td><?php $f->seq_field_d($count) ?></td>
           <td><?php $f->text_field_widsr('po_asl_document_id') ?></td>
           <td><?php echo $f->select_field_from_array('document_type', po_asl_document::$document_type_a, $$class->document_type, '', 'medium', 1, '', $readonly1); ?></td>
           <td><?php echo $f->select_field_from_array('document_line_id', $document_number_a, $$class->document_line_id); ?></td>
           <td><?php echo $f->date_fieldAnyDay('start_date', $$class->start_date); ?></td>
           <td><?php echo $f->date_fieldAnyDay('end_date', $$class->end_date); ?></td>
           <td><?php $f->text_field_wid('priority'); ?></td>
          </tr>
          <?php
          $count = $count + 1;
         }
         ?>
        </tbody>
       </table>
      </div>
      <div id="tabsLine-2" class="tabContent">
      </div>
     </div>

    </div>
   </div> 
  </form>
 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="po_asl_document" ></li>
  <li class="line_key_field" data-line_key_field="document_type" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="po_asl_document" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="po_asl_document_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="po_asl_document" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>