<?php

if (!empty($$class->ledger_id)) {
 $all_periods = gl_period::find_all_periods($$class->ledger_id);
 $period_name_stmt = form::select_field_from_object('period_id', $all_periods, 'gl_period_id', 'period_name', $$class->period_id, 'gl_period_id', '', '', '', 1);
}
?>