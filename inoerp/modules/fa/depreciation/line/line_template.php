<div id ="form_line" class="form_line"><span class="heading">Depreciation Lines </span>
 <div id="tabsLine">
  <ul class="tabMain">
   <li><a href="#tabsLine-1">Asset & Amounts</a></li>
   <li><a href="#tabsLine-2">Future</a></li>
  </ul>
  <div class="tabContainer"> 
   <form action=""  method="post" id="fa_depreciation_line_line"  name="fa_depreciation_line_line">
    <div id="tabsLine-1" class="tabContent">
     <table class="form_table">
      <thead> 
       <tr>
        <th>Action</th>
        <th>Line Id</th>
        <th>Asset</th>
        <th>Dprn Amount</th>
        <th>Unscheduled Amt</th>
        <th>Total Dprn</th>
        <th>Account</th>
        <th>Cost Before Dprn</th>
        <th>NBV Before Dprn</th>
        <th>Salvage</th>
       </tr>
      </thead>
      <tbody class="form_data_line_tbody fa_depreciation_line_values" >
       <?php
       $count = 0;
       $fa_depreciation_line_object_ai = new ArrayIterator($fa_depreciation_line_object);
       $fa_depreciation_line_object_ai->seek($position);
       while ($fa_depreciation_line_object_ai->valid()) {
        $fa_depreciation_line = $fa_depreciation_line_object_ai->current();
        if (!empty($$class_second->asset_id)) {
         $asset_i = fa_asset::find_by_id($$class_second->asset_id);
         if (!empty($asset_i->asset_number)) {
          $$class_second->asset_number = $asset_i->asset_number;
         }
        }else{
         $$class_second->asset_number = null;
        }
        ?>         
        <tr class="fa_depreciation_line<?php echo $count ?>">
         <td>    
          <ul class="inline_action">
           <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
           <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
           <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($fa_depreciation_line->fa_depreciation_line_id); ?>"></li>           
           <li><?php echo form::hidden_field('fa_depreciation_header_id', $$class->fa_depreciation_header_id); ?></li>
          </ul>
         </td>
         <td><?php form::number_field_wid2sr('fa_depreciation_line_id'); ?></td>
         <td><?php
          $f->text_field_wid2r('asset_id');
          $f->hidden_field('asset_number', $$class_second->asset_number);
          ?></td>
         <td><?php form::number_field_wid2('depreciation_amount'); ?></td>
         <td><?php form::number_field_wid2('unschedule_amount'); ?></td>
         <td><?php form::number_field_wid2('total_depreciation_amount'); ?></td>
         <td><?php $f->ac_field_wid2('depreciation_account_id'); ?></td>
         <td><?php form::number_field_wid2sr('cost_before_depreciation'); ?></td>
         <td><?php form::number_field_wid2sr('nbv_before_depreciation'); ?></td>
         <td><?php form::number_field_wid2sr('salvage_value_bd'); ?></td>
        </tr>
        <?php
        $fa_depreciation_line_object_ai->next();
        if ($fa_depreciation_line_object_ai->key() == $position + $per_page) {
         break;
        }
        $count = $count + 1;
       }
       ?>
      </tbody>
     </table>
    </div>
    <div id="tabsLine-2" class="tabContent">

    </div>
   </form>
  </div>

 </div>
</div> 