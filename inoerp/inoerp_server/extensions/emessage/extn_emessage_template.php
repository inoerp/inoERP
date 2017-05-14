<div id="extn_emessage_line_divId">
 <?php   echo (!empty($show_message)) ? $show_message : "";  ?> 
 <!--    End of place for showing error messages-->
 <div id ="form_header">
  <span class="heading"><?php echo gettext('Message Box'); ?></span>
  <div class="tabContainer"> 
   <div class="container bootstrap snippet">
    <div class="row">
     <div  id="msg-list" class="col-lg-3 col-md-3">
      <a href="#" class="btn btn-default btn-sm btn-block" role="button" id="new-emsg"><i class="glyphicon glyphicon-edit"></i> <?php echo gettext('Compose'); ?></a>
      <ul class="nav nav-pills nav-stacked">
       <li class="hidden"><input type="hidden" id="current_user_id" value="<?php echo $$class->from_user_id ?>"><li>
        <?php
        if (!empty($msg_lists) && is_array($msg_lists)) {
         foreach ($msg_lists as $msg_i) {
          if (!empty($msg_i->image_file_id)) {
           $profile_image = $f->show_existing_image($msg_i->image_file_id, 'img-vs media-object img-circle');
          }
          if (empty($profile_image)) {
           $profile_image = '<j class="img-circle">' . ucwords(substr($msg_i->username, 0, 1)) . '</j>';
          }
          echo "<li class='msg-lists clickable' data-extn_emessage_header_id='{$msg_i->extn_emessage_header_id}'><span class='ms-list-img pull-left'>$profile_image</span>";
          echo "<span class='msg-list-username'> " . $msg_i->username . '</span>';
          echo '<span class="msg-list-userid hidden" data-user_id= "' . $msg_i->user_id . '"></span>';
          echo "</li>";
         }
        } else {
         echo '</i>No messages</li>';
        }
        ?>
      </ul>

     </div>
     <form  method="post" id="extn_emessage_line" name="extn_emessage_line"  >
      <div id="msg-box-right" class="col-lg-9 col-md-9 ">
       <div class="portlet portlet-default ">
        <div class="portlet-heading">
         <div class="portlet-title">
          <h4><i class="fa fa-circle text-green"></i> 
           <?php
           echo '<ul class="inline_action"><li>';
           $f->l_val_field_d('user_name', 'ino_user', 'username', '', 'select user username');
           echo $f->hidden_field_withId('user_id', $$class->user_id);
           echo '</li></ul>';
           ?>
          </h4>
         </div>
         <div class="portlet-widgets">
          <label>Chat Mode</label> 
          <?php echo $f->select_field_from_array('chat_mode', extn_emessage_line::$chat_mode_a, '', 'chat_mode', ''); ?>
          <span class="divider"></span>
          <a data-toggle="collapse" data-parent="#accordion" href="#chat"><i class="fa fa-chevron-down"></i></a>
         </div>
         <div class="clearfix"></div>
        </div>
        <div id="chat" class="panel-collapse collapse in">
         <div>
          <div id="chat-content" class="portlet-body chat-widget" style="overflow-y: auto; width: auto; height: 300px;">
           <div id="chat-content-internal">
            <?php $f->hidden_field_d('extn_emessage_header_id'); ?>

           </div>
          </div>
         </div>
         <div class="portlet-footer">

          <div class="form-group">
           <textarea class="form-control remove_after_save" id="text_message"  name="text_message[]" placeholder="Enter message..."></textarea>
          </div>
          <div class="form-group-sm">
           <p class="col-md-3 text-muted small msg_creation_date">You can use Ctrl+S to send</p>
           <div class="hidden"><?php $f->hidden_field_d('from_user_id'); ?></div>
           <button type="button" class="col-md-1 btn  btn-default pull-right" id="save" >Send</button>
           <div class="clearfix"></div>
          </div>

         </div>
        </div>
       </div>
      </div>
     </form>
     <!-- /.col-md-4 -->
    </div>
   </div>   
  </div>

 </div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="extn_emessage_line" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="extn_emessage_line_id" ></li>
  <li class="dont_show_save_msg" data-dont_show_save_msg="1" ></li>
  <li class="form_header_id" data-form_header_id="extn_emessage_line" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="extn_emessage_line_id" ></li>
  <li class="btn1DivId" data-btn1DivId="extn_emessage_line_id" ></li>
 </ul>
</div>