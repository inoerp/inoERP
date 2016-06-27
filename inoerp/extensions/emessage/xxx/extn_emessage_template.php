<div class="row small-left-padding">
 <div id="form_all">
  <div id="form_headerDiv">
   <form  method="post" id="extn_emessage_line"  name="tax_code_line">
    <div id ="form_line" class="extn_emessage"><span class="heading"><?php echo gettext('All Messages') ?></span>
     <div id="tabsLine">
      <ul class="tabMain">
       <li><a href="#tabsLine-1"><?php echo gettext('Current Messages') ?></a></li>
       <li><a href="#tabsLine-2"><?php echo gettext('New Message') ?></a></li>
      </ul>
      <div class="tabContainer"> 
       <div id="tabsLine-1" class="tabContent">
        <div id="latest_messages">

         <div class="container bootstrap snippet">
          <div class="row">
           <div >
            <div class="portlet portlet-default">
             <div class="portlet-heading">
              <div class="portlet-title">
               <h4><i class="fa fa-circle text-green"></i>Jane Smith</h4>
              </div>
              <div class="portlet-widgets">
               <div class="btn-group">
                <button type="button" class="btn btn-white dropdown-toggle btn-xs" data-toggle="dropdown">
                 <i class="fa fa-circle text-green"></i> Status
                 <span class="caret"></span>
                </button>
                <ul class="dropdown-menu" role="menu">
                 <li><a href="#"><i class="fa fa-circle text-green"></i> Online</a>
                 </li>
                 <li><a href="#"><i class="fa fa-circle text-orange"></i> Away</a>
                 </li>
                 <li><a href="#"><i class="fa fa-circle text-red"></i> Offline</a>
                 </li>
                </ul>
               </div>
               <span class="divider"></span>
               <a data-toggle="collapse" data-parent="#accordion" href="#chat"><i class="fa fa-chevron-down"></i></a>
              </div>
              <div class="clearfix"></div>
             </div>
             <div id="chat" class="panel-collapse collapse in">
              <div>
               <div class="portlet-body chat-widget" style="overflow-y: auto; width: auto; height: 300px;">
                <div class="row">
                 <div class="col-lg-12">
                  <p class="text-center text-muted small">January 1, 2014 at 12:23 PM</p>
                 </div>
                </div>
                <div class="row">
                 <div class="col-lg-12">
                  <div class="media">
                   <a class="pull-left" href="#">
                    <img class="media-object img-circle" src="http://lorempixel.com/30/30/people/1/" alt="">
                   </a>
                   <div class="media-body">
                    <h4 class="media-heading">Jane Smith
                     <span class="small pull-right">12:23 PM</span>
                    </h4>
                    <p>Hi, I wanted to make sure you got the latest product report. Did Roddy get it to you?</p>
                   </div>
                  </div>
                 </div>
                </div>
                <hr>
                <div class="row">
                 <div class="col-lg-12">
                  <div class="media">
                   <a class="pull-left" href="#">
                    <img class="media-object img-circle" src="http://lorempixel.com/30/30/people/7/" alt="">
                   </a>
                   <div class="media-body">
                    <h4 class="media-heading">John Smith
                     <span class="small pull-right">12:28 PM</span>
                    </h4>
                    <p>Yeah I did. Everything looks good.</p>
                    <p>Did you have an update on purchase order #302?</p>
                   </div>
                  </div>
                 </div>
                </div>
                <hr>
               </div>
              </div>
              <div class="portlet-footer">

               <div class="form-group">
                <textarea class="form-control" placeholder="Enter message..."></textarea>
               </div>
               <div class="form-group">
                <button type="button" class="btn btn-default pull-right" id="save">Send</button>
                <div class="clearfix"></div>
               </div>

              </div>
             </div>
            </div>
           </div>
           <!-- /.col-md-4 -->
          </div>
         </div>                

        </div>

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