<form  method="post" id="sys_calendar"  name="sys_calendar">
 <span class="heading"><?php echo gettext('Calendar') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php echo gettext('Basic') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field('period_type', $$class->period_type); ?></li>
       <li><?php $f->l_text_field('user_id', $$class->user_id); ?></li>
      </ul>
     </div>
    </div>
   </div>
  </div>
 </div>

 <div id ="form_line" class="form_line"><span class="heading"><?php echo gettext('Viewing Options') ?></span>
  <div id="tabsLine">
   <ul class="tabMain">
    <li><a href="#tabsLine-1"><?php echo gettext('Day') ?></a></li>
    <li><a href="#tabsLine-2"><?php echo gettext('Week') ?></a></li>
    <li><a href="#tabsLine-3"><?php echo gettext('Month') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <table class="table table-hover table-sm cal cal-month">
      <thead>
       <tr class="cal-row cal-header">
        <th class="cal-th col2">Date :  <i class="cal-date"></i></th>
       </tr>
      </thead>
      <tbody>
       <?php
       $c_count = 1;
       for ($i = 23; $i > 0; $i--) {
        echo "<tr class='cal-row'>";
        echo "<td class='clickable cell_{$i}'>$c_count </td>";
        echo "</tr>";
        $c_count++;
       }
       ?>
      </tbody>
     </table>
    </div> 
    <div id="tabsLine-2" class="tabContent">
     <table class="table table-hover table-sm cal cal-week">
      <thead>
       <tr class="cal-row cal-header">
        <th class="cal-th col1"></th>
        <th class="cal-th col2">Mon <i class="cal-date"></i></th>
        <th class="cal-th col3">Tue <i class="cal-date"></i></th>
        <th class="cal-th col4">Wed <i class="cal-date"></i></th>
        <th class="cal-th col5">Thu <i class="cal-date"></i></th>
        <th class="cal-th col6">Fri <i class="cal-date"></i></th>
        <th class="cal-th col7">Sat <i class="cal-date"></i></th>
        <th class="cal-th col8">Sun <i class="cal-date"></i></th>
       </tr>
      </thead>
      <tbody>
       <?php
       $times = ' AM';
       for ($i = 24; $i > 0; $i--) {
        $rowclass = ($i % 2 == 0 ) ? 'cal-major' : 'cal-minor';
        echo "<tr class='cal-row $rowclass'>";
        for ($j = 0; $j <= 7; $j ++) {
         $tdval = ($j == 0 && $rowclass == 'cal-major') ? $i / 2 . ' AM ' : ' ';
         echo "<td class='clickable cell_{$i}_{$j}'> $tdval </td>";
        }
        echo "</tr>";
       }
       ?>
      </tbody>
     </table>
    </div> 
    <div id="tabsLine-3" class="tabContent">
     <table class="table table-hover table-sm cal cal-month">
      <thead>
       <tr class="cal-row cal-header">
        <th class="cal-th col2">Mon <i class="cal-date"></i></th>
        <th class="cal-th col3">Tue <i class="cal-date"></i></th>
        <th class="cal-th col4">Wed <i class="cal-date"></i></th>
        <th class="cal-th col5">Thu <i class="cal-date"></i></th>
        <th class="cal-th col6">Fri <i class="cal-date"></i></th>
        <th class="cal-th col7">Sat <i class="cal-date"></i></th>
        <th class="cal-th col8">Sun <i class="cal-date"></i></th>
       </tr>
      </thead>
      <tbody>
       <?php
       $c_count = 0;
       for ($i = 7; $i > 0; $i--) {
        echo "<tr class='cal-row height-100'>";
        for ($j = 0; $j <= 6; $j ++) {
         $c_count++;
         echo "<td class='clickable cell_{$i}_{$j}'>$c_count </td>";
        }
        echo "</tr>";
       }
       ?>
      </tbody>
     </table>
    </div> 
   </div>
  </div>
 </div> 
</form>

<div id="js_data">
 <ul id="js_saving_data">
  <li class="headerClassName" data-headerClassName="sys_calendar" ></li>
  <li class="savingOnlyHeader" data-savingOnlyHeader="true" ></li>
  <li class="primary_column_id" data-primary_column_id="sys_calendar_id" ></li>
  <li class="form_header_id" data-form_header_id="sys_calendar" ></li>
 </ul>

 <ul id="js_contextMenu_data">
  <li class="docHedaderId" data-docHedaderId="sys_calendar_id" ></li>
  <li class="btn1DivId" data-btn1DivId="sys_calendar" ></li>
 </ul>
</div>