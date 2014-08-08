<div id="all_contents">
 <div id="content_left"></div>
 <div id="content_right">
  <div id="content_right_left">
   <div id="content_top"></div>
   <div id="content">
    <div id="coa_structure_id">
     <div id="currency_conversion_divId">
      <!--    START OF FORM HEADER-->
      <div class="error"></div><div id="loading"></div>
      <?php echo (!empty($show_message)) ? $show_message : ""; $f= new inoform(); ?> 
      <!--    End of place for showing error messages-->
      <div id="form_all">
       <div id="form_headerDiv">
        <form action=""  method="post" id="gl_currency_conversion_line"  name="currency_conversion_line">
         <table class="form_table">
          <tr><td>
            <label>Conversion Type :</label>
            <?php echo $f->select_field_from_object('currency_conversion_type', gl_currency_conversion::currency_conversion_type(), 'option_line_code', 'option_line_value', $currency_conversion_type_h, 'currency_conversion_type', '', 1); ?>
            <a name="show" class="show gl_currency_conversion clickable">
             <img src="<?php echo HOME_URL; ?>themes/images/refresh.png"/></a> 
           </td></tr>
         </table>
         <div id ="form_line" class="gl_currency_conversion"><span class="heading">Region Details </span>
          <div id="tabsLine">
           <ul class="tabMain">
            <li><a href="#tabsLine-1">Rates </a></li>
            <li><a href="#tabsLine-2">Future </a></li>
           </ul>
           <div class="tabContainer"> 

            <div id="tabsLine-1" class="tabContent">
             <table class="form_table">
              <thead> 
               <tr>
                <th>Action</th>
                <th>Id</th>
                <th>From Currency</th>
                <th>To Currency</th>
                <th>Start Date</th>
                <th>End Date</th>
                <th>Rate</th>
                <th>Use Reverse Conversion</th>
                <th>Description</th>
               </tr>
              </thead>
              <tbody class="form_data_line_tbody currency_conversion_values" >
               <?php
                $count = 0;
                foreach ($currency_conversion_object as $gl_currency_conversion) {
                 if (empty($gl_currency_conversion->currency_conversion_type)) {
                  $gl_currency_conversion->currency_conversion_type = $currency_conversion_type_h;
                 }
                 ?>         
                 <tr class="currency_conversion_line<?php echo $count ?>">
                  <td>    
                   <ul class="inline_action">
                    <li class="add_row_img"><img  src="<?php echo HOME_URL; ?>themes/images/add.png"  alt="add new line" /></li>
                    <li class="remove_row_img"><img src="<?php echo HOME_URL; ?>themes/images/remove.png" alt="remove this line" /> </li>
                    <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($$class->gl_currency_conversion_id); ?>"></li>           
                    <li><?php echo form::hidden_field('currency_conversion_type', $currency_conversion_type_h); ?></li>
                   </ul>
                  </td>
                  <td><?php $f->text_field_dsr('gl_currency_conversion_id') ?></td>
                  <td><?php echo $f->select_field_from_object('from_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->from_currency, '', 'currency', 1); ?></td>
                  <td><?php echo $f->select_field_from_object('to_currency', option_header::currencies(), 'option_line_code', 'option_line_code', $$class->to_currency, '', 'currency', 1); ?></td>
                  <td><?php echo $f->date_fieldAnyDay('from_date', $$class->from_date); ?></td>
                  <td><?php echo $f->date_fieldAnyDay('to_date', $$class->to_date); ?></td>
                  <td><?php echo $f->number_field('rate', $$class->rate); ?></td>
                  <td><?php $f->checkBox_field_wid('use_reverse_conversion'); ?></td>
                  <td><?php $f->text_field_widl('description'); ?></td>
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

      <div id="pagination" style="clear: both;">
       <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
       ?>
      </div>
      <!--END OF FORM -->
     </div>
    </div>
    <!--   end of coa_structure_id-->
   </div>
   <div id="content_bottom"></div>
  </div>
  <div id="content_right_right"></div>
 </div>

</div>

<?php include_template('footer.inc') ?>