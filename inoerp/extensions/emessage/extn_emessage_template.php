<div class="row small-left-padding">
<div id="form_all">
 <div id="form_headerDiv">
  <form  method="post" id="extn_emessage_line"  name="tax_code_line">
   <div id ="form_line" class="extn_emessage"><span class="heading"><?php echo gettext('All Messages') ?></span>
    <div id="tabsLine">
     <ul class="tabMain">
      <li><a href="#tabsLine-1"><?php echo gettext('Latest Messages') ?></a></li>
      <li><a href="#tabsLine-2"><?php echo gettext('Archive') ?></a></li>
     </ul>
     <div class="tabContainer"> 
      <div id="tabsLine-1" class="tabContent">
       <div id="latest_messages">Chat Messages</div>
       <div id="latest_messages">Chat Form</div>
      </div>
      <div id="tabsLine-2" class="tabContent">
       <div id="old_messages">Old Messages</div>
      </div>
     </div>
    </div>
   </div> 
  </form>
 </div>
</div>
</div>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="primary_column_id" data-primary_column_id="extn_emessage_header_id" ></li>
  <li class="lineClassName" data-lineClassName="extn_emessage" ></li>
  <li class="line_key_field" data-line_key_field="text_message" ></li>
  <li class="single_line" data-single_line="false" ></li>
  <li class="form_line_id" data-form_line_id="extn_emessage" ></li>
 </ul>
 <ul id="js_contextMenu_data">
  <li class="docLineId" data-docLineId="extn_emessage_line_id" ></li>
  <li class="btn2DivId" data-btn2DivId="form_line" ></li>
  <li class="trClass" data-trclass="extn_emessage" ></li>
  <li class="tbodyClass" data-tbodyClass="form_data_line_tbody" ></li>
  <li class="noOfTabbs" data-noOfTabbs="2" ></li>
 </ul>
</div>