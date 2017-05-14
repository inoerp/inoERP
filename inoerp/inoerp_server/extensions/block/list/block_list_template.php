<div id='block_list_id'>
 <div id="all_contents">
  <div id="content_header"><span class='highlight'>Content header</span></div>
  <div id="content_left"><span class='highlight'>Content Left</span></div>
  <div id="content_right">
   <div id="content_right_left">
    <div id="content_top"><span class='highlight'>Content Top</span></div>
    <div id="content">
     <div id="main"> 
      <div id="structure">
       <div id="blocks_divId">
        <!--    START OF FORM HEADER-->
        <div id='observerDiv'></div>
        <div class="error"></div><div id="loading"></div>
        <?php echo (!empty($show_message)) ? $show_message : ""; ?> 
        <!--    End of place for showing error messages-->
        <div id="form_all">
         <form action=""  method="post" id="block_line"  name="block_line">
          <div id ="form_line" class="form_line">
           <span class="heading"><?php echo gettext('All Blocks') ?></span>
           <?php
           $block_list = new block();
           $result = $block_list->findALL_OrderBy_positionWeight();
           ?>
           <div id="tabsLine">
            <ul class="tabMain">
             <li><a href="#tabsLine-1"><?php echo gettext('Basic Info') ?></a></li>
             <li><a href="#tabsLine-2"><?php echo gettext('Visibility') ?></a></li>
            </ul>
            <div class="tabContainer"> 
             <div id="tabsLine-1" class="tabContent">
              <table class="form_table">
               <thead> 
                <tr>
                 <th><?php echo gettext('Action') ?></th>
                 <th><?php echo gettext('Block') ?></th>
                 <th><?php echo gettext('Block Id') ?>#</th>
                 <th><?php echo gettext('Name') ?></th>
                 <th><?php echo gettext('Title') ?></th>
                 <th><?php echo gettext('Position') ?></th>
                 <th><?php echo gettext('Weight') ?></th>
                 <th><?php echo gettext('Enabled') ?></th>
                 <th><?php echo gettext('Show Title') ?></th>
                 <th><?php echo gettext('Reference Table') ?>#</th>
                 <th><?php echo gettext('Cache Content') ?></th>
                </tr>
               </thead>
               <tbody class="form_data_line_tbody block_lines" >
                <?php
                $count = 1;
                foreach ($result as $block) {
                 $is_custom_block = 0;
                 if (($block->reference_table == 'block_content')) {
                  $is_custom_block = 1;
                 }
                 ?>         
                 <tr class="block_number<?php echo $count ?>">
                  <td>    
                   <ul class="inline_action">
                    <li class="edit"><a class="ajax-link" href="form.php?class_name=block&mode=9&block_id=<?php
                     echo htmlentities($block->block_id);
                     echo ($is_custom_block == 1) ? '&custom_block=1' : "";
                     ?>"><i class="fa fa-edit" title="update this block"></i></a></li>
                    <li class="remove_row_img"><i class="fa fa-minus-circle"></i></li>
                    <li><input type="checkbox" name="line_id_cb" value="<?php echo htmlentities($block->block_id); ?>"></li>
                   </ul>
                  </td>
                  <td><?php echo $count ?></td>
                  <td><?php echo $f->text_field('block_id', $block->block_id, '8', '', '', 1, 1); ?></td>
                  <td><?php
                   $readonly_b = ($block->reference_table == 'block_content') ? false : true;
                   echo $f->text_field('name', $block->name, '', '', '', '', $readonly_b);
                   ?></td>
                  <td><?php echo $f->text_field('title', $block->title); ?></td>
                  <td><?php echo $f->select_field_from_array('position', block::$position_array, $block->position); ?></td>
                  <td><?php echo $f->select_field_from_array('weight', dbObject::$position_array, $block->weight); ?></td>
                  <td><?php echo $f->checkBox_field('enabled_cb', $block->enabled_cb); ?></td>
                  <td><?php echo $f->checkBox_field('show_title_cb', $block->show_title_cb); ?></td>
                  <td><?php echo $f->text_field('reference_table', $block->reference_table, '', '', '', 1, 1); ?></td>
                  <td><?php echo $f->checkBox_field('cached_cb', $block->cached_cb); ?></td>
                  <?php
                  $count++;
                 }
                 ?>
               </tbody>
              </table>
             </div>
             <div id="tabsLine-2" class="tabContent">
              <table class="form_table">
               <thead> 
                <tr>
                 <th>Block #</th>
                 <th>Restrict to Role</th>
                 <th>Visibility</th>
                 <th>Visibility Option</th>

                </tr>
               </thead>
               <tbody class="form_data_line_tbody block_lines" >
                <?php
                $count = 1;
                foreach ($result as $block) {
                 $is_custom_block = 0;
                 if (($block->reference_table == 'block_content')) {
                  $is_custom_block = 1;
                 }
                 ?>         
                 <tr class="block_number<?php echo $count ?>">
                  <td><?php echo $count ?></td>
                  <td><?php echo $f->select_field_from_object('restrict_to_role', role_access::roles(), 'option_line_code', 'option_line_value', $block->restrict_to_role, 'role_code'); ?></td>  
                  <td><?php echo form::select_field_from_array('visibility_option', block::$visibility_option_array, $block->visibility_option); ?></td>
                  <td><textarea name="visibility" class="noformat" rows="1" cols="80"><?php echo base64_decode($block->visibility); ?></textarea></td>
                  <?php
                  $count++;
                 }
                 ?>
               </tbody>
              </table>
             </div>
            </div>

           </div>
          </div> 
         </form>
         </form>

        </div>
       </div>
      </div>
      <!--   end of structure-->
     </div>
    </div>
    <div id="content_bottom"><span class='highlight'>Content Bottom</span></div>
   </div>
   <div id="content_right_right"><span class='highlight'>Content Right Right</span></div>
  </div>

 </div>
 <span class='highlight'>Footer Top</span>

 <span class='highlight'>Footer Bottom</span>
</div>