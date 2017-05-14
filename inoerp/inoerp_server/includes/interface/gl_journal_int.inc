<?php

interface gl_journal_int {
 
 public function _save_journal_header();

 public function _save_journal_lines();

 public function _post_gl_process($class_primary_column_id);
}

?>