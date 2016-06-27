<?php

//used for creating credit /debit memo from transactions
 class ap_transaction_cm extends ap_transaction_line {

  private function _create_transaction_details() {
   $ap_th = new ap_transaction_header();
   $ap_th_i = $ap_th->findBy_id($this->ap_transaction_header_id);
   $po_d = new po_detail();
   $po_d_i = $po_d->findBy_id($this->po_detail_id);
   $ap_td = new ap_transaction_detail();
   $ap_td->ap_transaction_line_id = $this->ap_transaction_line_id;
   $ap_td->ap_transaction_header_id = $this->ap_transaction_line_id;
   $ap_td->detail_number = 1;
   $ap_td->account_type = 'ACCRUAL';
   $ap_td->description = '';
   $ap_td->amount = $this->inv_line_price;
   $ap_td->gl_amount = $ap_td->amount * $ap_th_i->exchange_rate;
   $ap_td->detail_ac_id = $this->detail_ac_id;
   $ap_td->status = '';
   $ap_td->reference_type = 'table';
   $ap_td->reference_key_name = 'po_header';
   $ap_td->reference_key_value = $this->po_header_id;
   $ap_td->po_header_id = $this->po_header_id;
   $ap_td->po_line_id = $this->po_line_id;
   $ap_td->po_detail_id = $this->po_detail_id;
   $ap_td->period_id = $ap_th_i->period_id;

   //update PO details
   foreach ($po_d_i as $pd_key => $pd_value) {
    $po_d->$pd_key = $pd_value;
   }
   $po_d->invoiced_quantity += $this->inv_line_quantity;
   $po_d->save();
   $ap_td->save();
  }
  
    public function _before_save() {
   $this->line_quantity = - $this->line_quantity;
   parent::_before_save();
  }

  public function _after_save() {
   if (($this->action === 'apply_transaction') && (!empty($this->ap_transaction_line_id)) && (!empty($this->po_line_id)) && (!empty($this->po_detail_id))) {
    $this->_create_transaction_details();
   }
   parent::_after_save();
  }

  public function multi_select_input_fields() {
   $multi_select_input = [
    'credit_line_quantity',
    'credit_unit_price',
   ];
   return $multi_select_input;
  }

  public function multi_select_hidden_fields() {
   $multi_select_hidden = [
    'action_class_name',
    'supplier_id',
    'action',
    'mode',
    'po_status',
    'supplier_site_id',
    'cm_transaction_header_id',
    'transaction_type',
    'account_type'
   ];

   return $multi_select_hidden;
  }

 }

//end of ap_transaction_line class
?>