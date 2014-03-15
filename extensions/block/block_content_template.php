<tr>
 <td colspan="2">
<div id="contentId"><label>Block Content : </label>
 <div class="information"> php codes start with <i>< ?php</i> But don't put  <i>?></i> at the end. </div>
 <textarea required name="content" class="noformat" rows="8" cols="80" placeholder='
           '><?php 
 echo base64_decode($block_content->content); ?></textarea>
</div>
 </td>
</tr>
<tr>
 <td>
<div id="block_info"><label>Block Info : </label>
 <input type="text"  name="info" value="<?php echo htmlentities($block_content->info); ?>" 
        size="50"  maxlength="250" class="subject" placeholder="Write a brief info on the block_content."> 
</div>
 </td>
  <td>
<div id="content_php_cb"><label>Block Content is PHP : </label>
 <?php echo form::checkBox_field('content_php_cb', $$class_second->content_php_cb); ?>
</div>
 </td>
</tr>
