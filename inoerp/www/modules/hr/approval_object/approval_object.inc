<?php

if (DB_TYPE == 'ORACLE') {
  $$class->object_value = stream_get_contents( $$class->object_value);
}
?>