<div id ="form_header">
 <form method="post" id="inv_abc_valuation"  name="inv_abc_valuation">
  <span class="heading"><?php  echo gettext('ABC Valuation') ?></span>
  <div class="large_shadow_box tabContainer">
   <ul class="column header_field"> 
    <li><?php $f->l_text_field_dr_withSearch('inv_abc_valuation_id') ?>
     <a name="show" href="form.php?class_name=inv_abc_valuation&<?php echo "mode=$mode"; ?>" class="show document_id inv_abc_valuation_id"><i class="fa fa-refresh"></i></a> 
    </li>
    <li><?php $f->l_text_field_d('valuation_name'); ?></li>
    <li><?php $f->l_text_field_d('description'); ?></li>
    <li><?php $f->l_select_field_from_object('criteria', inv_abc_valuation::abc_criteria(), 'option_line_code', 'option_line_value', $$class->criteria, 'criteria', '', 1, $readonly); ?></li>
    <li><?php $f->l_select_field_from_object('cost_type', bom_cost_type::find_all(), 'cost_type_code', 'cost_type', $$class->cost_type, 'cost_type', '', '', $readonly); ?></li>
    <li><?php $f->l_select_field_from_object('fp_mrp_header_id', fp_mrp_header::find_all(), 'fp_mrp_header_id', 'mrp_name', $$class->fp_mrp_header_id, 'fp_mrp_header_id', '', '', $readonly, '', '', '', 'org_id'); ?></li>
    <li><?php $f->l_select_field_from_object('fp_forecast_header_id', fp_forecast_header::find_all(), 'fp_forecast_header_id', 'forecast', $$class->fp_forecast_header_id, 'fp_forecast_header_id', '', '', $readonly, '', '', '', 'org_id'); ?></li>
   </ul>
  </div>
  <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Valuation Details') ?></span>
   <div id="tabsLine">
    <ul class="tabMain">
     <li><a href="#tabsLine-1"><?php echo gettext('Scope') ?></a></li>
     <li><a href="#tabsLine-2"><?php echo gettext('Action') ?></a></li>
    </ul>
    <div class="tabContainer"> 
     <div id="tabsLine-1" class="tabContent">
      <div> 
       <ul class="column header_field"> 
        <li><?php $f->l_select_field_from_object('scope_org_id', org::find_all_inventory(), 'org_id', 'org', $$class->scope_org_id, 'scope_org_id', '', 1, $readonly1); ?>        </li>
        <li><?php $f->l_select_field_from_object('scope_sub_inventory_id', subinventory::find_all_of_org_id($$class->scope_org_id), 'subinventory_id', 'subinventory', $$class->scope_sub_inventory_id, '', 'subinventory_id', '', $readonly); ?>			</li>
        <li><?php $f->l_text_field_d('scope_org_hirearchy_id'); ?> 					</li>
        <li><?php $f->l_select_field_from_object('scope_product_line', item::product_line(), 'option_line_code', 'option_line_value', $$class->scope_product_line, 'scope_product_line', '', '', $readonly); ?></li>
        <li><?php $f->l_date_fieldAnyDay('from_date', $$class->from_date); ?></li>
        <li><?php $f->l_date_fieldAnyDay('to_date', $$class->to_date); ?></li>
       </ul> 
      </div> 
     </div> 
     <div id="tabsLine-2"  class="tabContent">
      <div> 
       <ul class="column header_field">
        <li><label><?php echo gettext('Program') ?></label>
         <a class="button" target="_blank"
            href="program.php?class_name=inv_abc_valuation&program_name=prg_abc_valuation" ><?php echo gettext('New Valuation') ?></a>
        </li>
        <li id="document_print"><label><?php echo gettext('View') ?></label> <?php echo $result_stmt; ?>	</li>
       </ul>
      </div> 
     </div>
    </div>
   </div> 
  </div> 
 </form>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="inv_abc_valuation" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="inv_abc_valuation_id" ></li>
  <li class="form_header_id" data-form_header_id="inv_abc_valuation" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="inv_abc_valuation_id" ></li>
  <li class="btn1DivId" data-btn1DivId="inv_abc_valuation_id" ></li>
 </ul>
</div>