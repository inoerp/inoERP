<form  method="post" id="sys_calendar"  name="sys_calendar">
 <span class="heading"><?php echo gettext('Calendar') ?></span>
 <div id ="form_header">
  <div id="tabsHeader">
   <ul class="tabMain">
    <li><a href="#tabsHeader-1"><?php  echo gettext('Basic') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsHeader-1" class="tabContent">
     <div class="large_shadow_box"> 
      <ul class="column header_field">
       <li><?php $f->l_text_field_dr('username'); ?></li>
       <li><?php $f->l_text_field_dr('first_name'); ?></li>
       <li><?php $f->l_text_field_dr('last_name'); ?></li>
       <li><?php echo $f->hidden_field_withId('user_id', $$class->user_id); ?></li>
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
    <li><a href="#tabsLine-4"><?php echo gettext('Year') ?></a></li>
   </ul>
   <div class="tabContainer"> 
    <div id="tabsLine-1" class="tabContent">
     <table class="table table-hover table-sm cal cal-day">
      <thead>
       <tr class="cal-row cal-header">
        <th class="cal-th col1">Date <i class="cal-date"></i></th>
        <th class="cal-th col2">Events</th>
       </tr>
      </thead>
      <tbody class="cal-day-tbdy">
       <?php
       for ($i = 0; $i < 24; $i++) {
        $td_time = sys_calendar::convt_number_time($i);
        $rowclass = ($i % 2 == 0 ) ? 'cal-major' : 'cal-minor';
        echo "<tr class='cal-row $rowclass'>";
        for ($j = 0; $j <= 1; $j ++) {
         $tdval = ($j == 0 && $rowclass == 'cal-major') ? $i / 2 . ' AM' : ' ';
         $tdval = ($tdval == '0 AM') ? '12 AM' : $tdval;
         echo "<td class='clickable row_{$i} col_{$j}' time='{$td_time}'> $tdval </td>";
        }
        echo "</tr>";
       }
       for ($i = 0; $i < 24; $i++) {
        $td_time = sys_calendar::convt_number_time($i, 1);
        $rowclass = ($i % 2 == 0 ) ? 'cal-major' : 'cal-minor';
        echo "<tr class='cal-row $rowclass'>";
        for ($j = 0; $j <= 1; $j ++) {
         $tdval = ($j == 0 && $rowclass == 'cal-major') ? $i / 2 . ' PM' : ' ';
         $tdval = ($tdval == '0 PM') ? '12 PM' : $tdval;
         echo "<td class='clickable row_{$i} col_{$j}' time='{$td_time}'> $tdval </td>";
        }
        echo "</tr>";
       }
       ?>
      </tbody>
     </table>
    </div> 
    <div id="tabsLine-2" class="tabContent">
     <table class="table table-hover table-sm cal cal-week">
      <thead>
       <tr class="cal-row cal-header">
        <th class="cal-th col0"></th>
        <th class="cal-th col1"><?php echo gettext('Sun') ?> <i class="cal-date"></i></th>
        <th class="cal-th col2"><?php echo gettext('Mon') ?> <i class="cal-date"></i></th>
        <th class="cal-th col3"><?php echo gettext('Tue') ?> <i class="cal-date"></i></th>
        <th class="cal-th col4"><?php echo gettext('Wed') ?> <i class="cal-date"></i></th>
        <th class="cal-th col5"><?php echo gettext('Thu') ?> <i class="cal-date"></i></th>
        <th class="cal-th col6"><?php echo gettext('Fri') ?> <i class="cal-date"></i></th>
        <th class="cal-th col7"><?php echo gettext('Sat') ?> <i class="cal-date"></i></th>
       </tr>
      </thead>
      <tbody class="cal-week-tbdy">
       <?php
       for ($i = 0; $i < 24; $i++) {
        $td_time = sys_calendar::convt_number_time($i);
        $rowclass = ($i % 2 == 0 ) ? 'cal-major' : 'cal-minor';
        echo "<tr class='cal-row $rowclass'>";
        for ($j = 0; $j <= 7; $j ++) {
         $tdval = ($j == 0 && $rowclass == 'cal-major') ? $i / 2 . ' AM' : ' ';
         $tdval = ($tdval == '0 AM') ? '12 AM' : $tdval;
         echo "<td class='clickable row_{$i} col_{$j}' time='{$td_time}'> $tdval </td>";
        }
        echo "</tr>";
       }
       for ($i = 0; $i < 24; $i++) {
        $td_time = sys_calendar::convt_number_time($i, 1);
        $rowclass = ($i % 2 == 0 ) ? 'cal-major' : 'cal-minor';
        echo "<tr class='cal-row $rowclass'>";
        for ($j = 0; $j <= 7; $j ++) {
         $tdval = ($j == 0 && $rowclass == 'cal-major') ? $i / 2 . ' PM' : ' ';
         $tdval = ($tdval == '0 PM') ? '12 PM' : $tdval;
         echo "<td class='clickable row_{$i} col_{$j}' time='{$td_time}'> $tdval </td>";
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
        <th class="cal-th col1"><?php echo gettext('Sun') ?> <i class="cal-date"></i></th>
        <th class="cal-th col2"><?php echo gettext('Mon') ?> <i class="cal-date"></i></th>
        <th class="cal-th col3"><?php echo gettext('Tue') ?> <i class="cal-date"></i></th>
        <th class="cal-th col4"><?php echo gettext('Wed') ?> <i class="cal-date"></i></th>
        <th class="cal-th col5"><?php echo gettext('Thu') ?> <i class="cal-date"></i></th>
        <th class="cal-th col6"><?php echo gettext('Fri') ?> <i class="cal-date"></i></th>
        <th class="cal-th col7"><?php echo gettext('Sat') ?> <i class="cal-date"></i></th>
       </tr>
      </thead>
      <tbody class="cal-month-tbdy">
       <?php
       $c_count = 0;
       for ($i = 6; $i > 0; $i--) {
        echo "<tr class='cal-row height-100'>";
        for ($j = 0; $j <= 6; $j ++) {
         $c_count++;
         echo "<td class='clickable cell_{$c_count}'>$c_count </td>";
        }
        echo "</tr>";
       }
       ?>
      </tbody>
     </table>
    </div> 

    <div id="tabsLine-4" class="tabContent">
     <table class="table table-hover table-sm cal cal-year">
      <thead>
       <tr class="cal-row cal-header">
        <th class="cal-th col1"><?php echo gettext('Seq') ?> <i class="cal-date"></i></th>
        <th class="cal-th col2"><?php echo gettext('Title') ?> <i class="cal-date"></i></th>
        <th class="cal-th col3"><?php echo gettext('Start Date') ?> <i class="cal-date"></i></th>
        <th class="cal-th col4"><?php echo gettext('Start Time') ?> <i class="cal-date"></i></th>
        <th class="cal-th col5"><?php echo gettext('End Date') ?> <i class="cal-date"></i></th>
        <th class="cal-th col6"><?php echo gettext('End Time') ?> <i class="cal-date"></i></th>
        <th class="cal-th col7"><?php echo gettext('Location') ?> <i class="cal-date"></i></th>
        <th class="cal-th col7"><?php echo gettext('Event Id') ?> <i class="cal-date"></i></th>
       </tr>
      </thead>
      <tbody class="cal-year-tbdy">
       <?php
       $all_events = hr_event_header::find_by_year_user();
       if (empty($all_events)) {
        $all_events = [new hr_event_header()];
       }

       foreach ($all_events as $k => $event_i) {
        $k1 = $k + 1;
        $str_rpl_from = ['15', '45'];
        $str_rpl_to = ['00', '30'];
        $start_time = substr($event_i->start_time, 0, -3);
        $start_time_adj = str_replace($str_rpl_from, $str_rpl_to, $start_time);
        $end_time = substr($event_i->end_time, 0, -3);
        $end_time_adj = str_replace($str_rpl_from, $str_rpl_to, $end_time);
        $event_link = '<a type="button" class="btn btn-default btn-xs" target="_new" href="form.php?class_name=hr_event_header&mode=9&hr_event_header_id=' . $event_i->hr_event_header_id . '">' . $event_i->title . '</a>';
        echo "<tr class='cal-row'>";
        echo "<td class='clickable col1 row-{$k1}'>$k1 </td>";
        echo "<td class='clickable col2 row-{$k1}'> $event_link </td>";
        echo "<td class='clickable col3 row-{$k1}' event_id='{$event_i->hr_event_header_id}' start_date='{$event_i->start_date}' start_time='{$start_time_adj}' end_date='{$event_i->end_date}' end_time='{$end_time_adj}' > $event_i->start_date </td>";
        echo "<td class='clickable col4 row-{$k1}' > " . $start_time . "</td>";
        echo "<td class='clickable col5 row-{$k1}' > $event_i->end_date </td>";
        echo "<td class='clickable col6 row-{$k1}' >  " . $end_time . " </td>";
        echo "<td class='clickable col7 row-{$k1}'> $event_i->location </td>";
        echo "<td class='clickable col8 row-{$k1}'> $event_i->hr_event_header_id </td>";
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