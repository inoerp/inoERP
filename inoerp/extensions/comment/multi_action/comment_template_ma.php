<div id="multi_select">
<div id="extn_comment_divId">
 <div class="row small-top-margin" >
  <div id="searchForm" ><div class='hideDiv_input fa fa-minus-circle clickable'></div>
   <div class='hideDiv_input_element'><?php echo!(empty($search_form)) ? $search_form : ""; ?></div></div>

  <div id="searchResult">
   <form  method="post" id="extn_comment"  name="extn_comment">
    <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Comments') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Basic') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('Details') ?></a></li>
      </ul>
      <div class="tabContainer">
       <div id="tabsLine-1" class="tabContent">
        <table class="form_table">
         <thead> 
          <tr>
           <th><?php echo gettext('Action') ?></th>
           <th><?php echo gettext('Comment Id') ?></th>
           <th><?php echo gettext('Refernce Table') ?></th>
           <th><?php echo gettext('Refernec Id') ?></th>
           <th><?php echo gettext('Subject') ?></th>
           <th><?php echo gettext('Published') ?></th>
           <th><?php echo gettext('Weightage') ?></th>
           <th><?php echo gettext('Comment By') ?></th>
					 <!--<th><?php // echo gettext('Action') ?></th>-->
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php $f = new inoform();
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $extn_comment) {
            ?>         
            <tr class="extn_comment_line<?php echo $count ?>">
             <td>    
              <ul class="inline_action">
               <li class="add_row_img"><i class="fa fa-plus-circle"></i></li>
               <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
               <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($extn_comment->extn_comment_id); ?>"></li>           
              </ul>
             </td>
             <td><?php form::text_field_widsr('extn_comment_id'); ?></td>
             <td><?php echo $f->text_field_widr('reference_table'); ?></td>
						 <td><?php echo $f->text_field_widr('reference_id'); ?></td>
						 <td><?php echo $f->text_field_widr('subject'); ?></td>
						 <td><?php echo $f->checkBox_field_wid('published_cb'); ?></td>
						 <td><?php echo $f->text_field_wid('weightage'); ?></td>
						 <td><?php echo $f->text_field_wid('comment_by'); ?></td>
						 <!--<td><?php // echo $f->select_field_from_array('comment_action', ['unpublish' => 'Unpublish', 'delete' => 'Delete'], '' ,'' ,'medium'); ?></td>-->
             
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
         <thead> 
          <tr>
           <th><?php echo gettext('Comment Id') ?></th>
           <th><?php echo gettext('Comment') ?></th>
          </tr>
         </thead>
         <tbody class="form_data_line_tbody">
          <?php
          $count = 0;
          if (!empty($search_result)) {
           foreach ($search_result as $extn_comment) {
            ?>         
            <tr class="extn_comment_line<?php echo $count ?>">
             <td><?php echo $$class->extn_comment_id; ?></td>
             <td><?php echo $f->text_area_ap(['name' => 'extn_comment' , 'value' => $extn_comment->extn_comment , 'column_size' => 120]); ?></td>

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
 </div>
 <!--END OF FORM HEADER-->
 <div class="row small-top-margin">
  <div id="pagination" style="clear: both;">
   <?php echo!(empty($pagination_statement)) ? $pagination_statement : "";
   ?>
  </div>
 </div>

</div>
</div>
<div id="js_data">
 <ul id="js_saving_data">
  <li class="lineClassName" data-lineClassName="extn_comment" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="false" ></li>
  <li class="form_header_id" data-form_header_id="extn_comment" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="btn1DivId" data-btn1DivId="extn_comment"></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>

