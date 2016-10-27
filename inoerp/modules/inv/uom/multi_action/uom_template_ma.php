<div id="uom_divId" class="multi_select_page">
 <div class="row small-top-margin" id="multi_select">
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>
  <div id ="searchResult">
   <form action=""  method="post" id="uom"  name="uom">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Unit Of Measure Details')?> </span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic Info')?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('UOM Relation')?></a></li>

      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <tr>
          <th><?php echo gettext('Action')?></th>
          <th><?php echo gettext('UOM Id')?></th>
          <th><?php echo gettext('UOM')?></th>
          <th><?php echo gettext('Class')?></th>
          <th><?php echo gettext('Description')?></th>
          <th><?php echo gettext('Primary')?></th>
          <th><?php echo gettext('EF Id')?></th>
          <th><?php echo gettext('Status')?></th>
          <th><?php echo gettext('Rev Enabled')?></th>
          <th><?php echo gettext('Rev')?>#</th>
         </tr>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $uom) {
            ?>         
            <tr class="uom_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($uom->uom_id); ?>"></li>           
              </ul>
             </td>
             <td><?php form::text_field_widsr('uom_id'); ?></td>
             <td><?php form::text_field_wid('uom_name'); ?></td>
             <td><?php echo form::select_field_from_object('class', uom::uom_class(), 'option_line_code', 'option_line_code', $$class->class, 'class', $readonly); ?></td>
             <td><?php form::text_field_wid('description'); ?></td>
             <td><?php $f->checkBox_field_d('primary_cb'); ?></td>
             <td><?php form::text_field_wid('ef_id'); ?></td>
             <td><?php echo form::status_field($$class->status, $readonly); ?></td>
             <td><?php echo form::checkBox_field('rev_enabled_cb' . $count, $$class->rev_enabled_cb, 'rev_enabled_cb', $readonly); ?></td> 
             <td><?php form::text_field_wids('rev_number'); ?></td> 
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
        </table>
       </div>
       <div id="tabsLine-2" class="scrollElement" class="tabContent">
        <table class="form_table">
         <tr>
          <th> <?php echo gettext('Primary UOM Id')?></th>
          <th> <?php echo gettext('Primary UOM')?></th>
          <th> <?php echo gettext('Operator')?> </th>
          <th> <?php echo gettext('Primary Relation')?> </th>
         </tr>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $uom) {
            if (!empty($uom->primary_uom_id)) {
             $primar_uom_i = uom::find_by_id($uom->primary_uom_id);
             $uom->primary_uom = $primar_uom_i->uom_name;
            } else {
             $uom->primary_uom = null;
            }
            ?>         
            <tr class="uom_line<?php echo $count ?>">
             <td><?php $f->text_field_widsr('primary_uom_id'); ?></td>
             <td><?php $f->text_field_wid('primary_uom'); ?>
              <i class="fa fa-search primary_uom_id select_popup clickable"></i>
             </td>
             <td><input type="image"  src="<?php echo HOME_URL; ?>themes/images/multiply.png" alt="multiply"/> 
             </td> 
             <td>	<?php $f->text_field_wid('primary_relation'); ?> </td> 
            </tr>
            <?php
            $count = $count + 1;
           }
          }
          ?>
         </tbody>
         <!--                  Showing a blank form for new entry-->

        </table>
       </div>
      </div>
     </div>
    </div> 
   </form>
  </div>
  <!--END OF FORM HEADER-->
 </div>

 <div class="row small-top-margin">
  <div id="pagination" style="clear: both;">
   <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
   ?>
  </div>
 </div>

</div>
<script type=text/javascript>
 function setValFromSelectPage(uom_id, uom_name) {
  this.uom_id = uom_id;
  this.uom_name = uom_name;
 }

 setValFromSelectPage.prototype.setVal = function () {
  var uom_id = this.uom_id;
  var uom_name = this.uom_name;
  var primaryUom_fieldClass = '.' + localStorage.getItem("primaryUom_fieldClass");
  primaryUom_fieldClass = primaryUom_fieldClass.replace(/\s+/g, '.');

  if (uom_id) {
   if (primaryUom_fieldClass) {
    $('#content').find(primaryUom_fieldClass).find('.primary_uom').val(uom_name);
    $('#content').find(primaryUom_fieldClass).find('.primary_uom_id').val(uom_id);
    localStorage.removeItem("primaryUom_fieldClass");
   }
  }
 };

 $(document).ready(function () {
  //selecting primary UOM Id on multi action
  $('body').on("click", '.primary_uom_id.select_popup', function () {
   var primaryUom_fieldClass = $(this).closest('tr').prop('class');
   localStorage.setItem("primaryUom_fieldClass", primaryUom_fieldClass);
   void window.open('select.php?class_name=uom', '_blank',
           'width=1000,height=800,TOOLBAR=no,MENUBAR=no,SCROLLBARS=yes,RESIZABLE=yes,LOCATION=no,DIRECTORIES=no,STATUS=no');
  });
  //add new row in multi action template

 });
</script>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="uom" ></li>
  <li class="lineClassName" data-lineClassName="uom" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="uom" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="adm_task_type"></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>
