
CREATE OR REPLACE VIEW po_all_v
(
po_header_id, bu_org_id, po_type, po_number, supplier_id, supplier_site_id, buyer, currency, doc_currency, header_amount, po_status,
payment_term_id,exchange_rate,exchange_rate_type,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_line_id, line_type, po_line_number,	item_id_m,  kit_cb, revision_name, item_description, line_description, line_quantity, 
unit_price, line_price, gl_line_price, gl_tax_amount,
reference_doc_type, reference_doc_number,
item_number, uom_id, item_status,serial_generation, lot_generation,
po_detail_id, shipment_number, receving_org_id, org_id, subinventory_id, locator_id, requestor, 
quantity,received_quantity, open_quantity,
need_by_date, promise_date,
 accepted_quantity, delivered_quantity, invoiced_quantity, paid_quantity,
charge_ac_id, accrual_ac_id,budget_ac_id, ppv_ac_id,
receving_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
po_header.po_header_id, po_header.bu_org_id, po_header.po_type, po_header.po_number, po_header.supplier_id, 
po_header.supplier_site_id, po_header.buyer, po_header.currency, po_header.doc_currency, po_header.header_amount, po_header.po_status,
po_header.payment_term_id,po_header.exchange_rate,po_header.exchange_rate_type,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id_m, po_line.kit_cb,  po_line.revision_name, 
po_line.item_description, po_line.line_description, 
po_line.line_quantity, po_line.unit_price, po_line.line_price, po_line.gl_line_price, po_line.gl_tax_amount,
 po_line.reference_doc_type, po_line.reference_doc_number,
item.item_number, item.uom_id, item.item_status,item.serial_generation, item.lot_generation,
po_detail.po_detail_id, po_detail.shipment_number, po_line.receving_org_id, po_line.receving_org_id, po_detail.subinventory_id, 
po_detail.locator_id, po_detail.requestor, 
po_detail.quantity, IFNULL(po_detail.received_quantity,0), po_detail.quantity - IFNULL(po_detail.received_quantity,0), 
po_detail.need_by_date, po_detail.promise_date,
 po_detail.accepted_quantity, po_detail.delivered_quantity, 
po_detail.invoiced_quantity, po_detail.paid_quantity,
po_detail.charge_ac_id, po_detail.accrual_ac_id,po_detail.budget_ac_id, po_detail.ppv_ac_id,
org.org,
po_header.created_by, po_header.creation_date, po_header.last_update_by, po_header.last_update_date

FROM po_header 
LEFT JOIN supplier ON po_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN po_line ON po_header.po_header_id = po_line.po_header_id
LEFT JOIN item ON po_line.item_id_m = item.item_id_m AND item.org_id = po_line.receving_org_id
LEFT JOIN po_detail ON po_line.po_line_id = po_detail.po_line_id
LEFT JOIN org ON po_line.receving_org_id = org.org_id ;



CREATE OR REPLACE VIEW wip_wo_routing_v
(
item_number, item_description, uom_id, item_id_m, wo_number, org_id, wip_accounting_group_id, quantity, completed_quantity,
routing_sequence, department_id, wip_wo_routing_detail_id, wip_wo_routing_line_id, wip_wo_header_id,
resource_sequence, resource_id,resource_usage,resource_schedule,required_quantity, applied_quantity, 
charge_type
)
AS
SELECT item.item_number, item.item_description, item.uom_id,
wwh.item_id_m, wwh.wo_number, wwh.org_id, wwh.wip_accounting_group_id, wwh.quantity, wwh.completed_quantity,
wwrl.routing_sequence,wwrl.department_id,
wwrd.wip_wo_routing_detail_id, wwrd.wip_wo_routing_line_id, wwrd.wip_wo_header_id,wwrd.resource_sequence,wwrd.resource_id,wwrd.resource_usage,wwrd.resource_schedule,wwrd.required_quantity, wwrd.applied_quantity, wwrd.charge_type
FROM wip_wo_routing_detail wwrd
LEFT JOIN wip_wo_routing_line wwrl ON wwrl.wip_wo_routing_line_id = wwrd.wip_wo_routing_line_id
LEFT JOIN wip_wo_header wwh ON wwh.wip_wo_header_id = wwrd.wip_wo_header_id
LEFT JOIN item ON item.item_id_m = wwh.item_id_m and item.org_id = wwh.org_id ;

CREATE OR REPLACE VIEW ap_import_claim_v
(
claim_number, hr_expense_header_id,   bu_org_id,   hr_employee_id,   claim_date,    status,   purpose,   
doc_currency,   department_id,   reason,   currency,   exchange_rate_type,   exchange_rate,   header_amount,
supplier_id, first_name, last_name, identification_id
)
AS
SELECT 
eh.claim_number, eh.hr_expense_header_id,   eh.bu_org_id,   eh.hr_employee_id,   eh.claim_date,    eh.status,   eh.purpose,   
eh.doc_currency,   eh.department_id,   eh.reason,   eh.currency,   eh.exchange_rate_type,   eh.exchange_rate,   eh.header_amount,
user.supplier_id , he.first_name, he.last_name, he.identification_id

FROM hr_expense_header eh,
ino_user user,
hr_employee he
  
WHERE eh.status = 'APPROVED'
AND user.hr_employee_id = eh.hr_employee_id  
AND he.hr_employee_id = eh.hr_employee_id  ;


CREATE OR REPLACE VIEW ap_payment_all_v
(
ap_payment_header_id, bu_org_id, payment_type,
payment_number, supplier_id, supplier_site_id, from_bank_header_id,
header_amount,  currency, document_number, payment_status, gl_journal_header_id,
ap_payment_line_id, line_number, amount, line_description,
ap_transaction_header_id, transaction_type, transaction_number,
hr_employee_id, apth_currency, apth_header_amount, transaction_status,
paid_amount,apth_payment_status,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number
)
AS
SELECT 
apph.ap_payment_header_id, apph.bu_org_id, apph.payment_type,
apph.payment_number, apph.supplier_id, apph.supplier_site_id, apph.from_bank_header_id,
apph.header_amount,  apph.currency, apph.document_number, apph.payment_status, apph.gl_journal_header_id,
appl.ap_payment_line_id, appl.line_number, appl.amount, appl.line_description,
apth.ap_transaction_header_id, apth.transaction_type, apth.transaction_number,
apth.hr_employee_id, apth.currency, apth.header_amount, apth.transaction_status,
apth.paid_amount, apth.payment_status,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number

FROM ap_payment_header apph,
ap_payment_line appl,
ap_transaction_header apth,
supplier,
supplier_site

WHERE apph.ap_payment_header_id = appl.ap_payment_header_id
AND appl.ap_transaction_header_id = apth.ap_transaction_header_id
AND apph.supplier_id = supplier.supplier_id
AND apph.supplier_site_id = supplier_site.supplier_site_id;



CREATE OR REPLACE VIEW ap_payment_trnx_v
(
ap_transaction_header_id, bu_org_id, transaction_type, transaction_number,
supplier_id, 
supplier_site_id, exchange_rate, hr_employee_id, currency, header_amount, transaction_status,
payment_term_id, paid_amount, payment_status,
ledger_id,period_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
po_number,po_type, buyer,
payment_term, description,
ap_transaction_line_id, line_type, line_number,	item_id_m, item_description, line_description, 
inv_line_quantity, inv_unit_price, inv_line_price, gl_inv_line_price,
po_header_id,    po_line_id,    po_detail_id,
ref_transaction_header_id,    ref_transaction_line_id,
item_number, uom_id, item_status,
created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
ap_transaction_header.ap_transaction_header_id, ap_transaction_header.bu_org_id, ap_transaction_header.transaction_type, ap_transaction_header.transaction_number,
ap_transaction_header.supplier_id, 
ap_transaction_header.supplier_site_id, ap_transaction_header.exchange_rate, ap_transaction_header.hr_employee_id, ap_transaction_header.currency, ap_transaction_header.header_amount, ap_transaction_header.transaction_status,
ap_transaction_header.payment_term_id, ap_transaction_header.paid_amount, ap_transaction_header.payment_status,
ap_transaction_header.ledger_id,ap_transaction_header.period_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
ph.po_number,ph.po_type, ph.buyer,
payment_term.payment_term, payment_term.description,
ap_transaction_line.ap_transaction_line_id, ap_transaction_line.line_type, ap_transaction_line.line_number,	ap_transaction_line.item_id_m, ap_transaction_line.item_description, ap_transaction_line.line_description, 
ap_transaction_line.inv_line_quantity, ap_transaction_line.inv_unit_price, ap_transaction_line.inv_line_price, ap_transaction_line.gl_inv_line_price,
ap_transaction_line.po_header_id,    ap_transaction_line.po_line_id,    ap_transaction_line.po_detail_id,
ap_transaction_line.ref_transaction_header_id,    ap_transaction_line.ref_transaction_line_id,
item.item_number, item.uom_id, item.item_status,
ap_transaction_header.created_by, ap_transaction_header.creation_date, ap_transaction_header.last_update_by, ap_transaction_header.last_update_date

FROM ap_transaction_header 
LEFT JOIN supplier ON ap_transaction_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON ap_transaction_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON ap_transaction_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN ap_transaction_line ON ap_transaction_header.ap_transaction_header_id = ap_transaction_line.ap_transaction_header_id
LEFT JOIN item ON ap_transaction_line.item_id_m = item.item_id_m and item.item_id_m = item.item_id
LEFT JOIN po_header ph ON ph.po_header_id = ap_transaction_line.po_header_id

WHERE IFNULL(ap_transaction_header.paid_amount,0) < ap_transaction_header.header_amount
AND (ap_transaction_header.payment_status  IS NULL OR  ap_transaction_header.payment_status != 'FULLY_PAID');






CREATE OR REPLACE VIEW ap_po_matching_v
(
po_header_id, bu_org_id, po_type, po_number, supplier_id, supplier_site_id, buyer, currency, doc_currency, header_amount, po_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_line_id, line_type, po_line_number,	item_id_m, item_description, line_description, line_quantity, unit_price,
line_price,gl_line_price,gl_tax_amount,tax_amount,
item_number, uom_id, item_status,
po_detail_id, shipment_number, receving_org_id, subinventory_id, locator_id, requestor, 
quantity,received_quantity, receiving_open_quantity,
need_by_date, promise_date,
 accepted_quantity, delivered_quantity, invoiced_quantity, paid_quantity, invoicing_open_quantity,
charge_ac_id, accrual_ac_id,budget_ac_id, ppv_ac_id,
receving_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
po_header.po_header_id, po_header.bu_org_id, po_header.po_type, po_header.po_number, po_header.supplier_id, 
po_header.supplier_site_id, po_header.buyer, po_header.currency, po_header.doc_currency, po_header.header_amount, po_header.po_status,
po_header.payment_term_id,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_line.po_line_id, po_line.line_type, po_line.line_number,	po_line.item_id_m, po_line.item_description, po_line.line_description, 
po_line.line_quantity, po_line.unit_price, po_line.line_price,po_line.gl_line_price,po_line.gl_tax_amount,po_line.tax_amount,
item.item_number, item.uom_id, item.item_status,
po_detail.po_detail_id, po_detail.shipment_number, po_line.receving_org_id, po_detail.subinventory_id, 
po_detail.locator_id, po_detail.requestor, 
po_detail.quantity, IFNULL(po_detail.received_quantity,0) as received_quantity, po_detail.quantity - IFNULL(po_detail.received_quantity,0) as receiving_open_quantity, 
po_detail.need_by_date, po_detail.promise_date,
 po_detail.accepted_quantity, po_detail.delivered_quantity, 
po_detail.invoiced_quantity, po_detail.paid_quantity,
CASE po_detail.invoice_match_type 
 WHEN 'THREE_WAY' THEN IFNULL(po_detail.received_quantity,0) - IFNULL(po_detail.invoiced_quantity,0) 
 ELSE po_detail.quantity - IFNULL(po_detail.invoiced_quantity,0) 
 END as invoicing_open_quantity,
po_detail.charge_ac_id, po_detail.accrual_ac_id,po_detail.budget_ac_id, po_detail.ppv_ac_id,
org.org,
po_header.created_by, po_header.creation_date, po_header.last_update_by, po_header.last_update_date
FROM po_header 
LEFT JOIN supplier ON po_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN po_line ON po_header.po_header_id = po_line.po_header_id
LEFT JOIN item ON po_line.item_id_m = item.item_id_m AND item.org_id = po_line.receving_org_id
LEFT JOIN org ON po_line.receving_org_id = org.org_id ,
po_detail 
WHERE po_header.po_status='APPROVED'
AND po_header.po_type IN ('BLANKET_RELEASE', 'STANDARD')
AND po_line.po_line_id = po_detail.po_line_id
AND (( IFNULL(po_detail.invoiced_quantity,0) < po_detail.quantity AND ( po_detail.invoice_match_type = 'TWO_WAY' OR ISNULL(po_detail.invoice_match_type)))
OR(( IFNULL(po_detail.invoiced_quantity,0) < IFNULL(po_detail.received_quantity,0) AND ( po_detail.invoice_match_type = 'THREE_WAY' ))
    ))
AND po_detail.po_detail_id IS NOT NULL;




CREATE OR REPLACE VIEW supplier_all_v
(
supplier_id,supplier_number, supplier_name ,
supplier_site_id, supplier_site_number, supplier_site_name,
 supplier_type, tax_country, created_by,
customer_id, status,
creation_date, last_update_by, last_update_date,
 supplier_bu_id, org_id, liability_account_id,
payable_account_id, payment_discount_account_id, pre_payment_account_id,
site_tax_country, site_tax_reg_no, site_status,
currency, payment_term_id)
AS
SELECT 
su.supplier_id,su.supplier_number, su.supplier_name ,
ss.supplier_site_id, ss.supplier_site_number, ss.supplier_site_name,
 su.supplier_type, su.tax_country, su.created_by,
su.ar_customer_id, su.status,
su.creation_date, su.last_update_by, su.last_update_date,
 sb.supplier_bu_id, sb.org_id, liability_account_id,
payable_account_id, payment_discount_account_id, pre_payment_account_id,
ss.site_tax_country, ss.site_tax_reg_no, ss.status,
ss.currency, ss.payment_term_id

FROM supplier su
LEFT JOIN supplier_site ss ON ss.supplier_id = su.supplier_id
LEFT JOIN supplier_bu sb ON su.supplier_id = sb.supplier_id ;



CREATE OR REPLACE VIEW ap_transaction_all_v
(
ap_transaction_header_id, bu_org_id, transaction_type, transaction_number, supplier_id, supplier_site_id, hr_employee_id, currency, 
header_amount, transaction_status, payment_term_id, paid_amount, payment_status,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
po_number,po_type, buyer,
payment_term, payment_term_description,
ap_transaction_line_id, line_type, line_number,	item_id_m, item_description, line_description, inv_line_quantity, inv_unit_price, inv_line_price,
po_header_id, po_line_id, po_detail_id, ref_transaction_header_id, ref_transaction_line_id,
item_number, uom_id, item_status,
ap_transaction_detail_id,  account_type, detail_description, amount, detail_ac_id, created_by, 
creation_date, last_update_by, last_update_date
)
AS
SELECT 
ap_transaction_header.ap_transaction_header_id, ap_transaction_header.bu_org_id, ap_transaction_header.transaction_type, ap_transaction_header.transaction_number,
ap_transaction_header.supplier_id, 
ap_transaction_header.supplier_site_id, ap_transaction_header.hr_employee_id, ap_transaction_header.currency, ap_transaction_header.header_amount, ap_transaction_header.transaction_status,
ap_transaction_header.payment_term_id, ap_transaction_header.paid_amount, ap_transaction_header.payment_status,
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
ph.po_number,ph.po_type, ph.buyer,
payment_term.payment_term, payment_term.description,
ap_transaction_line.ap_transaction_line_id, ap_transaction_line.line_type, ap_transaction_line.line_number,	ap_transaction_line.item_id_m, ap_transaction_line.item_description, ap_transaction_line.line_description, 
ap_transaction_line.inv_line_quantity, ap_transaction_line.inv_unit_price, ap_transaction_line.inv_line_price,
ap_transaction_line.po_header_id,    ap_transaction_line.po_line_id,    ap_transaction_line.po_detail_id,
ap_transaction_line.ref_transaction_header_id,    ap_transaction_line.ref_transaction_line_id,
item.item_number, item.uom_id, item.item_status,
ap_transaction_detail.ap_transaction_detail_id, ap_transaction_detail.account_type, ap_transaction_detail.description, 
ap_transaction_detail.amount, ap_transaction_detail.detail_ac_id, 
ap_transaction_header.created_by, ap_transaction_header.creation_date, ap_transaction_header.last_update_by, ap_transaction_header.last_update_date

FROM ap_transaction_header 
LEFT JOIN supplier ON ap_transaction_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON ap_transaction_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON ap_transaction_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN ap_transaction_line ON ap_transaction_header.ap_transaction_header_id = ap_transaction_line.ap_transaction_header_id
LEFT JOIN item ON ap_transaction_line.item_id_m = item.item_id_m and item.item_id_m = item.item_id
LEFT JOIN ap_transaction_detail ON ap_transaction_line.ap_transaction_line_id = ap_transaction_detail.ap_transaction_line_id
LEFT JOIN po_header ph ON ph.po_header_id = ap_transaction_line.po_header_id;




CREATE OR REPLACE VIEW ar_customer_v
(
ar_customer_id,customer_number, customer_name ,
ar_customer_site_id, customer_site_number, customer_site_name,
status,creation_date, last_update_by, last_update_date,
 site_tax_country, site_tax_reg_no, site_status,
currency, payment_term_id)
AS
SELECT 
ac.ar_customer_id,ac.customer_number, ac.customer_name ,
acs.ar_customer_site_id, acs.customer_site_number, acs.customer_site_name,
ac.status,ac.creation_date, ac.last_update_by, ac.last_update_date,
 acs.site_tax_country, acs.site_tax_reg_no, acs.status,
acs.currency, acs.payment_term_id

FROM ar_customer ac
LEFT JOIN ar_customer_site acs ON acs.ar_customer_id = ac.ar_customer_id;






CREATE OR REPLACE VIEW ar_transaction_all_v
(
 ar_transaction_header_id,  bu_org_id,  transaction_type,  transaction_class,  transaction_number,
 ar_customer_id,  ar_customer_site_id,  document_owner,  description,  ship_to_id,
 bill_to_id,  header_amount,  receipt_amount,  tax_amount,  currency,
 doc_currency,  receivable_ac_id,  payment_term_id,  exchange_rate_type,  exchange_rate,
 transaction_status,  document_date,  document_number,  ledger_id,  trnx_period_id,
 payment_term_date,  sales_person,  receipt_method,  approval_status,  receipt_status,
 trnx_reference_type,  trnx_reference_key_name,  trnx_reference_key_value,  trnx_sd_so_header_id,
 ar_transaction_line_id,   line_number,  item_id_m,
 item_description,  inv_line_quantity,  inv_unit_price,  tax_code_id,
 so_tax_amount,  gl_inv_line_price,  gl_tax_amount,  inv_line_price,  trnx_line_type,
 line_description,  asset_cb,  uom_id,  status,  line_source,
 sd_so_header_id,  trnx_sd_so_line_id,  sd_so_detail_id,  period_id,
 reference_type,  reference_key_name,  reference_key_value, 
  customer_name, customer_number,
  customer_site_name, customer_site_number,
  sd_so_line_id, line_type, so_line_number,	 
  kit_cb, kit_configured_cb, bom_config_header_id,	wip_wo_header_id, 
  line_quantity,
  picked_quantity, shipped_quantity, unit_price, line_price, line_status,
  requested_date, promise_date , schedule_ship_date ,actual_ship_date,
  item_number, item_uom_id, item_status,
  org, shipping_org_id,
  created_by, creation_date, last_update_by, last_update_date,
  address,country,postal_code,phone,email,website,
  address_b, country_b, postal_code_b,   phone_b, email_b, website_b,
  payment_term, payment_term_description
)
AS
  SELECT
  ath.ar_transaction_header_id,   ath.bu_org_id,   ath.transaction_type,   ath.transaction_class,   ath.transaction_number,
  ath.ar_customer_id,   ath.ar_customer_site_id,   ath.document_owner,   ath.description,   ath.ship_to_id,
  ath.bill_to_id,   ath.header_amount,   ath.receipt_amount,   ath.tax_amount,   ath.currency,
  ath.doc_currency,   ath.receivable_ac_id,   ath.payment_term_id,   ath.exchange_rate_type,   ath.exchange_rate,
  ath.transaction_status,   ath.document_date,   ath.document_number,   ath.ledger_id,   ath.period_id,
  ath.payment_term_date,   ath.sales_person,   ath.receipt_method,   ath.approval_status,   ath.receipt_status,
  ath.reference_type,   ath.reference_key_name,   ath.reference_key_value,   ath.sd_so_header_id,
  atl.ar_transaction_line_id,    atl.line_number,   atl.item_id_m,
  atl.item_description,   atl.inv_line_quantity,   atl.inv_unit_price,   atl.tax_code_id,
  atl.tax_amount,   atl.gl_inv_line_price,   atl.gl_tax_amount,   atl.inv_line_price,   atl.line_type,
  atl.line_description,   atl.asset_cb,   atl.uom_id,   atl.status,   atl.line_source,
  atl.sd_so_header_id,   atl.sd_so_line_id,   atl.sd_so_detail_id,   atl.period_id,
  atl.reference_type,   atl.reference_key_name,   atl.reference_key_value, 
  ar_customer.customer_name, ar_customer.customer_number,
  ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
  sdsl.sd_so_line_id, sdsl.line_type, sdsl.line_number,	
  sdsl.kit_cb, sdsl.kit_configured_cb, sdsl.bom_config_header_id,	sdsl.wip_wo_header_id, 
  sdsl.line_quantity,
  sdsl.picked_quantity, sdsl.shipped_quantity, sdsl.unit_price, sdsl.line_price, sdsl.line_status,
  sdsl.requested_date, sdsl.promise_date , sdsl.schedule_ship_date ,sdsl.actual_ship_date,
  item.item_number, item.uom_id, item.item_status,
  org.org, sdsl.shipping_org_id,
  sdsl.created_by, sdsl.creation_date, sdsl.last_update_by, sdsl.last_update_date,
  ship_address.address,ship_address.country,ship_address.postal_code,ship_address.phone,ship_address.email,ship_address.website,
  bill_address.address as address_b,bill_address.country as country_b,bill_address.postal_code as postal_code_b,
  bill_address.phone as phone_b,bill_address.email as email_b,bill_address.website as website_b,
  payment_term.payment_term, payment_term.description
  FROM 
  ar_customer, 
  address  ship_address,
  address  bill_address,
  ar_transaction_line atl
  LEFT JOIN ar_transaction_header ath ON ath.ar_transaction_header_id = atl.ar_transaction_header_id
  LEFT JOIN ar_customer_site ON ath.ar_customer_site_id = ar_customer_site.ar_customer_site_id
  LEFT JOIN payment_term ON ath.payment_term_id = payment_term.payment_term_id
  LEFT JOIN sd_so_line sdsl ON atl.sd_so_line_id = sdsl.sd_so_line_id 
  LEFT JOIN sd_so_header sdsh ON sdsh.sd_so_header_id = sdsl.sd_so_header_id
  LEFT JOIN  org ON sdsl.shipping_org_id = org.org_id
  LEFT JOIN item ON sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id

  WHERE ath.ar_customer_id = ar_customer.ar_customer_id
  AND ship_address.address_id = ath.ship_to_id
  AND bill_address.address_id = ath.bill_to_id;
  
  
  
  CREATE OR REPLACE VIEW ar_transaction_interface_v
(
po_requisition_header_id, bu_org_id, po_requisition_type, po_requisition_number, supplier_id, supplier_site_id, buyer, currency, header_amount, po_requisition_status,
payment_term_id,
supplier_name, supplier_number,
supplier_site_name, supplier_site_number,
payment_term, payment_term_description,
po_requisition_line_id, line_type, po_requisition_line_number,	item_id_m, item_description, 
line_description, line_quantity, unit_price, line_price,  receving_org_id,
item_number, uom_id, item_status,
po_requisition_detail_id, shipment_number, sub_inventory_id, locator_id, requestor, quantity,
need_by_date, promise_date,
received_quantity, accepted_quantity, delivered_quantity, invoiced_quantity, paid_quantity,	order_number,
ship_to_org, created_by, creation_date, last_update_by, last_update_date
)
AS
SELECT 
po_requisition_header.po_requisition_header_id, po_requisition_header.bu_org_id, po_requisition_header.po_requisition_type, po_requisition_header.po_requisition_number, po_requisition_header.supplier_id, 
po_requisition_header.supplier_site_id, po_requisition_header.buyer, po_requisition_header.currency, po_requisition_header.header_amount, po_requisition_header.requisition_status,
IFNULL(po_requisition_header.payment_term_id, supplier_site.payment_term_id),
supplier.supplier_name, supplier.supplier_number,
supplier_site.supplier_site_name, supplier_site.supplier_site_number,
payment_term.payment_term, payment_term.description,
po_requisition_line.po_requisition_line_id, po_requisition_line.line_type, po_requisition_line.line_number,	po_requisition_line.item_id_m, po_requisition_line.item_description, po_requisition_line.line_description, 
po_requisition_line.line_quantity, po_requisition_line.unit_price, po_requisition_line.line_price,po_requisition_line.receving_org_id,
item.item_number, item.uom_id, item.item_status,
po_requisition_detail.po_requisition_detail_id, po_requisition_detail.shipment_number,  po_requisition_detail.sub_inventory_id, 
po_requisition_detail.locator_id, po_requisition_detail.requestor, po_requisition_detail.quantity, po_requisition_detail.need_by_date, po_requisition_detail.promise_date,
po_requisition_detail.received_quantity, po_requisition_detail.accepted_quantity, po_requisition_detail.delivered_quantity, 
po_requisition_detail.invoiced_quantity, po_requisition_detail.paid_quantity,	po_requisition_detail.order_number,
org.org,
po_requisition_header.created_by, po_requisition_header.creation_date, po_requisition_header.last_update_by, po_requisition_header.last_update_date

FROM po_requisition_header 
LEFT JOIN supplier ON po_requisition_header.supplier_id = supplier.supplier_id
LEFT JOIN supplier_site ON po_requisition_header.supplier_site_id = supplier_site.supplier_site_id
LEFT JOIN payment_term ON po_requisition_header.payment_term_id = payment_term.payment_term_id
LEFT JOIN po_requisition_line ON po_requisition_header.po_requisition_header_id = po_requisition_line.po_requisition_header_id
LEFT JOIN item ON po_requisition_line.item_id_m = item.item_id_m
LEFT JOIN po_requisition_detail ON po_requisition_line.po_requisition_line_id = po_requisition_detail.po_requisition_line_id
LEFT JOIN org ON po_requisition_line.receving_org_id = org.org_id
WHERE  po_requisition_header.requisition_status = 'APPROVED'
AND (po_requisition_detail.order_number IS NULL OR po_requisition_detail.order_number = '');



CREATE OR REPLACE VIEW bom_all_v
(
bom_header_id, item_id_m, alternate_bom, org_id , bom_revision, effective_date, common_bom_item_id_m,
item_number, item_description, uom_id, item_type, item_status, bom_type,
costing_enabled_cb, make_buy,
org, org_type, org_status, org_description, org_code
)
AS
SELECT 
bh.bom_header_id, bh.item_id_m, bh.alternate_bom, bh.org_id , bh.bom_revision, bh.effective_date, bh.common_bom_item_id_m,
item.item_number, item.item_description, item.uom_id, item.item_type, item.item_status, item.bom_type,
item.costing_enabled_cb, item.make_buy,
org.org, org.type, org.status, org.description, org.code

FROM bom_header bh
LEFT JOIN item ON item.item_id_m = bh.item_id_m AND item.org_id = bh.org_id
LEFT JOIN org ON org.org_id = bh.org_id;



CREATE OR REPLACE VIEW bom_routing_v
(
bom_routing_header_id, item_id_m, alternate_routing, org_id, routing_revision, 
effective_date, common_routing_item_id_m, description, completion_subinventory, 
completion_locator, ef_id, created_by, creation_date, last_update_by, last_update_date,
item_number, item_description, uom_id, item_type, item_status, bom_type,
costing_enabled_cb, make_buy,
org, type, status, org_description, code, subinventory,locator
)
AS
SELECT 
bom_routing_header_id, brh.item_id_m, brh.alternate_routing, brh.org_id, brh.routing_revision, 
brh.effective_date, brh.common_routing_item_id_m, brh.description, brh.completion_subinventory, 
brh.completion_locator, brh.ef_id, brh.created_by, brh.creation_date, brh.last_update_by, brh.last_update_date,
item.item_number, item.item_description, item.uom_id, item.item_type, item.item_status, item.bom_type,
item.costing_enabled_cb, item.make_buy,
org.org, org.type, org.status, org.description, org.code, sub.subinventory,loc.locator

FROM bom_routing_header brh
LEFT JOIN item ON item.item_id_m = brh.item_id_m AND item.org_id = brh.org_id
LEFT JOIN org ON org.org_id = brh.org_id
LEFT JOIN subinventory sub ON sub.subinventory_id = brh.completion_subinventory
LEFT JOIN locator loc ON loc.locator_id = brh.completion_locator;



CREATE OR REPLACE VIEW bom_routing_line_v
(
bom_routing_header_id_h, item_id_m, alternate_routing, org_id, routing_revision, 
effective_date, common_routing_item_id_m, description_h, completion_subinventory, 
completion_locator,
bom_routing_line_id, bom_routing_header_id, routing_sequence, standard_operation_id,
department_id, description, count_point_cb, auto_charge_cb, backflush_cb,
minimum_transfer_quantity, lead_time_percentage, effective_start_date,
effective_end_date, eco_number, eco_implemented_cb, include_in_rollup_cb,
referenced_cb, yield, cumm_yield
)
AS
SELECT 
brh.bom_routing_header_id as bom_routing_header_id_h, brh.item_id_m, brh.alternate_routing, brh.org_id, brh.routing_revision, 
brh.effective_date, brh.common_routing_item_id_m, brh.description as description_h, brh.completion_subinventory, 
brh.completion_locator,
brl.bom_routing_line_id, brl.bom_routing_header_id, brl.routing_sequence, brl.standard_operation_id,
brl.department_id, brl.description, brl.count_point_cb, brl.auto_charge_cb, brl.backflush_cb,
brl.minimum_transfer_quantity, brl.lead_time_percentage, brl.effective_start_date,
brl.effective_end_date, brl.eco_number, brl.eco_implemented_cb, brl.include_in_rollup_cb,
brl.referenced_cb, brl.yield, brl.cumm_yield

FROM bom_routing_header brh,
bom_routing_line brl

WHERE brh.bom_routing_header_id = brl.bom_routing_header_id
AND (brh.common_routing_item_id_m IS NULL OR  brh.common_routing_item_id_m = 0)

UNION

SELECT 
brhc.bom_routing_header_id as bom_routing_header_id_h, brhc.item_id_m, brhc.alternate_routing, brhc.org_id, brhc.routing_revision, 
brhc.effective_date, brhc.common_routing_item_id_m, brhc.description as description_h, brhc.completion_subinventory, 
brhc.completion_locator,
brl.bom_routing_line_id, brl.bom_routing_header_id, brl.routing_sequence, brl.standard_operation_id,
brl.department_id, brl.description, brl.count_point_cb, brl.auto_charge_cb, brl.backflush_cb,
brl.minimum_transfer_quantity, brl.lead_time_percentage, brl.effective_start_date,
brl.effective_end_date, brl.eco_number, brl.eco_implemented_cb, brl.include_in_rollup_cb,
brl.referenced_cb, brl.yield, brl.cumm_yield

FROM bom_routing_header brh,
bom_routing_header brhc,
bom_routing_line brl

WHERE brh.bom_routing_header_id = brl.bom_routing_header_id
AND (brhc.common_routing_item_id_m IS NOT NULL OR brhc.common_routing_item_id_m = 0)
AND brhc.common_routing_item_id_m = brh.item_id_m;







CREATE OR REPLACE VIEW cst_gross_margin_v
(
ar_transaction_header_id,  bu_org_id,  transaction_type,  transaction_class,  transaction_number,
ar_customer_id,  ar_customer_site_id,  document_owner,  description,  ship_to_id,
bill_to_id,  header_amount,  currency,exchange_rate,
doc_currency, document_number,  ledger_id,  period_id,period_name,
sales_person,reference_key_name_ath,  reference_key_value_ath,  sd_so_header_id_ath,
ar_transaction_line_id,    line_number,   item_id_m, ar_transaction_header_id_atl,
item_description,   inv_line_quantity,   inv_unit_price, 
line_type,   line_description, 
sd_so_header_id,    reference_key_name,   reference_key_value, 
customer_name, customer_number,
customer_site_name, customer_site_number,
sd_so_line_id, line_type_so_line, unit_price,
item_number, org, shipping_org_id,
inv_unit_price_ledgc, address,country, cst_item_cost_header_id,frozen_cost,
gross_profit, gross_margin
)
AS
  SELECT
  ath.ar_transaction_header_id,   ath.bu_org_id,   ath.transaction_type,   ath.transaction_class,   ath.transaction_number,
  ath.ar_customer_id,   ath.ar_customer_site_id,   ath.document_owner,   ath.description,   ath.ship_to_id,
  ath.bill_to_id,   ath.header_amount,   ath.currency, ath.exchange_rate,
  ath.doc_currency,  ath.document_number,   ath.ledger_id,   ath.period_id, gp.period_name,
  ath.sales_person, ath.reference_key_name,   ath.reference_key_value,   ath.sd_so_header_id,
  atl.ar_transaction_line_id,    atl.line_number,   atl.item_id_m, atl.ar_transaction_header_id,
  atl.item_description,   atl.inv_line_quantity,   atl.inv_unit_price, 
  atl.line_type,   atl.line_description, 
  atl.sd_so_header_id,   atl.reference_key_name,   atl.reference_key_value, 
  ar_customer.customer_name, ar_customer.customer_number,
  ar_customer_site.customer_site_name, ar_customer_site.customer_site_number,
  sdsl.sd_so_line_id, sdsl.line_type, sdsl.unit_price,
  item.item_number, org.org, sdsl.shipping_org_id,
 (atl.inv_unit_price * ath.exchange_rate ) as inv_unit_price_ledgc,
  ship_address.address,ship_address.country, cich.cst_item_cost_header_id, SUM(amount) as frozen_cost,
  (IFNULL((atl.inv_unit_price * ath.exchange_rate ), 0 ) - IFNULL(SUM(amount), 0 )) as gross_profit,
  ROUND((IFNULL((atl.inv_unit_price * ath.exchange_rate ), 0 ) - IFNULL(SUM(amount), 0 ))/IFNULL((atl.inv_unit_price * ath.exchange_rate ), 1 ) , 5)*100 as gross_margin
  
  FROM 
  ar_customer, 
  address as ship_address,
  gl_period gp,
  ar_transaction_line atl
  LEFT JOIN ar_transaction_header ath ON ath.ar_transaction_header_id = atl.ar_transaction_header_id
  LEFT JOIN ar_customer_site ON ath.ar_customer_site_id = ar_customer_site.ar_customer_site_id
  LEFT JOIN sd_so_line sdsl ON atl.sd_so_line_id = sdsl.sd_so_line_id 
  LEFT JOIN sd_so_header sdsh ON sdsh.sd_so_header_id = sdsl.sd_so_header_id
  LEFT JOIN org ON sdsl.shipping_org_id = org.org_id
  LEFT JOIN item ON sdsl.item_id_m = item.item_id_m AND item.org_id = sdsl.shipping_org_id
  LEFT JOIN cst_item_cost_header cich ON cich.item_id_m = item.item_id_m AND item.org_id = cich.org_id AND bom_cost_type = 'FROZEN'
  LEFT JOIN cst_item_cost_line cicl ON cicl.cst_item_cost_header_id = cich.cst_item_cost_header_id

  WHERE ath.ar_customer_id = ar_customer.ar_customer_id
  AND ship_address.address_id = ath.ship_to_id
  AND gp.gl_period_id = ath.period_id

 GROUP BY cst_item_cost_header_id, atl.ar_transaction_line_id;
 
 
 CREATE OR REPLACE VIEW onhand_v
(onhand_id, item_number, item_description, org_name, subinventory, locator,
uom_id,onhand, item_id_m, org_id, subinventory_id, 
locator_id, lot_id, serial_id, reservable_onhand, 
transactable_onhand, lot_status, serial_status,  
secondary_uom_id, onhand_status, ef_id, created_by, 
creation_date, last_update_by, last_update_date)
AS
SELECT onhand.onhand_id, 
item.item_number, item.item_description, org.org, subinventory.subinventory, locator.locator,
onhand.uom_id,onhand.onhand,
onhand.item_id_m, onhand.org_id, onhand.subinventory_id, 
onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand, 
onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
onhand.creation_date, onhand.last_update_by, onhand.last_update_date

FROM onhand 
LEFT JOIN item ON onhand.item_id_m = item.item_id_m
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
LEFT JOIN locator ON onhand.locator_id = locator.locator_id;



 CREATE OR REPLACE VIEW onhand_summary_v
(onhand_id, item_number, item_description, org_name, 
uom_id,onhand, item_id_m, org_id, reservable_onhand, 
transactable_onhand
)
AS
SELECT onhand.onhand_id, item.item_number, item.item_description, 
org.org, onhand.uom_id, Sum(onhand.onhand),
onhand.item_id_m, onhand.org_id,  onhand.reservable_onhand, 
onhand.transactable_onhand
FROM onhand 
LEFT JOIN item ON onhand.item_id_m = item.item_id_m and item.org_id = onhand.org_id
LEFT JOIN org ON onhand.org_id = org.org_id
GROUP BY  onhand.onhand_id, item.item_number, item.item_description, 
org.org, onhand.uom_id, onhand.item_id_m, onhand.org_id,  onhand.reservable_onhand, 
onhand.transactable_onhand;


CREATE OR REPLACE VIEW cst_item_cost_sum_v
(
cst_item_cost_header_id, standard_cost
)
AS
    SELECT  ich.cst_item_cost_header_id cst_item_cost_header_id, sum(icl.amount) as standard_cost
    from cst_item_cost_header ich,
    cst_item_cost_line icl 
    WHERE icl.cst_item_cost_header_id = ich.cst_item_cost_header_id
    GROUP BY ich.cst_item_cost_header_id;
	

CREATE OR REPLACE VIEW cst_item_cost_v
(
item_number, item_description, item_id_m,org_id, org,
 sales_price, purchase_price, 
cst_item_cost_header_id, bom_cost_type, standard_cost
)
AS
SELECT item.item_number, item.item_description, cich.item_id_m as item_id_m ,cich.org_id as org_id, org.org, cich.sales_price as sales_price, 
cich.purchase_price as purchase_price, cich.cst_item_cost_header_id as cst_item_cost_header_id, 
cich.bom_cost_type as bom_cost_type , icsv.standard_cost as standard_cost
FROM cst_item_cost_header cich,
cst_item_cost_sum_v icsv,
item,
org
WHERE icsv.cst_item_cost_header_id = cich.cst_item_cost_header_id 
AND item.item_id_m = cich.item_id_m AND item.org_id = cich.org_id
AND org.org_id = cich.org_id;



CREATE OR REPLACE VIEW fa_asset_transaction_v
(
fa_asset_transaction_id, fa_asset_id, fa_asset_book_info_id, fa_asset_book_id,
transaction_type, quantity, amout, gl_journal_header_id, gl_journal_line_id,
description, created_by, creation_date, last_update_by,  last_update_date,
asset_number,  tag_number, serial_number, key_number, asset_description, manufacturer,
model_number, warrranty_number, lease_number, physical_inventory_cb, 
asset_book_name, bu_org_id, type, primary_fa_asset_book_id, book_description
)
AS
SELECT
fat.fa_asset_transaction_id, fat.fa_asset_id, fat.fa_asset_book_info_id, fat.fa_asset_book_id,
fat.transaction_type, fat.quantity, fat.amout, fat.gl_journal_header_id, fat.gl_journal_line_id,
fat.description, fat.created_by, fat.creation_date, fat.last_update_by,  fat.last_update_date,
ast.asset_number,  ast.tag_number, ast.serial_number, ast.key_number, ast.description as asset_description, ast.manufacturer,
ast.model_number, ast.warrranty_number, ast.lease_number, ast.physical_inventory_cb, 
fab.asset_book_name, fab.bu_org_id, fab.type, fab.primary_fa_asset_book_id, fab.description

from fa_asset_transaction fat,
fa_asset ast,
fa_asset_book fab

WHERE ast.fa_asset_id = fat.fa_asset_id
AND fab.fa_asset_book_id = fat.fa_asset_book_id;




CREATE OR REPLACE VIEW fp_forecast_line_date_v
(
fp_forecast_line_date_id, fp_forecast_line_id,forecast,forecast_group,org,
item_number, uom_name,  item_description,forecast_date,bucket_type, original_quantity, current_quantity, source, item_id_m, uom_id
)
AS
SELECT
fld.fp_forecast_line_date_id, fld.fp_forecast_line_id,fh.forecast,fg.forecast_group,org.org,
item.item_number, uom.uom_name,  item.item_description,fld.forecast_date,fl.bucket_type, fld.original_quantity, fld.current_quantity, fld.source, fl.item_id_m, item.uom_id

FROM 
fp_forecast_line_date fld,
fp_forecast_line fl,
org,
fp_forecast_header fh 
LEFT JOIN fp_forecast_group fg ON fg.fp_forecast_group_id = fh.forecast_group_id,
item 
LEFT JOIN uom ON uom.uom_id = item.uom_id

WHERE fl.fp_forecast_line_id = fld.fp_forecast_line_id
AND fl.fp_forecast_header_id = fh.fp_forecast_header_id
AND item.item_id_m = fl.item_id_m
AND item.org_id = fh.org_id
AND org.org_id = fh.org_id;



CREATE OR REPLACE VIEW fp_forecast_over_consumption_v
(
forecast_group, org, so_number, line_number,
item_number, uom_name,  item_description,schedule_ship_date,
quantity,item_id_m, uom_id,fp_forecast_consumption_id, sd_so_line_id,
sd_so_header_id
)
AS
SELECT
fg.forecast_group,org.org,sosh.so_number, sosl.line_number,
item.item_number, uom.uom_name,  item.item_description,sosl.schedule_ship_date,
foc.quantity,sosl.item_id_m, item.uom_id,foc.fp_forecast_consumption_id, foc.sd_so_line_id,
sosl.sd_so_header_id

FROM 
fp_forecast_consumption foc,
fp_forecast_group fg,
sd_so_line sosl,
sd_so_header sosh,
org,
item 
LEFT JOIN uom ON uom.uom_id = item.uom_id

WHERE foc.sd_so_line_id = sosl.sd_so_line_id
AND fg.fp_forecast_group_id = foc.fp_forecast_group_id
AND item.item_id_m = sosl.item_id_m
AND item.org_id = sosl.shipping_org_id
AND org.org_id = sosl.shipping_org_id
AND sosh.sd_so_header_id = sosl.sd_so_header_id
AND foc.quantity < 0;




CREATE OR REPLACE VIEW minmax_board_v
(onhand_id, item_number, item_description, product_line, org_name, subinventory, locator,
uom_id,onhand, minmax_min_quantity, minmax_max_quantity, open_quantity,
standard_cost, onhand_value,
item_id_m, revision_name, org_id, subinventory_id, subinventory_type,
locator_id, lot_id, serial_id, reservable_onhand, 
transactable_onhand, lot_status, serial_status,  
secondary_uom_id, onhand_status, ef_id, created_by, 
creation_date, last_update_by, last_update_date, min_delta)
AS
SELECT onhand.onhand_id, 
item.item_number, item.item_description, item.product_line,
org.org, subinventory.subinventory, locator.locator,
onhand.uom_id,onhand.onhand, item.minmax_min_quantity, item.minmax_max_quantity, po_summary.open_quantity,
cic.standard_cost, (onhand.onhand * cic.standard_cost) as onhand_value,
onhand.item_id_m, onhand.revision_name, onhand.org_id, onhand.subinventory_id, subinventory.type,
onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand, 
onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
onhand.creation_date, onhand.last_update_by, onhand.last_update_date,
(onhand.onhand + po_summary.open_quantity - item.minmax_min_quantity)as min_delta
FROM onhand  
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
LEFT JOIN locator ON onhand.locator_id = locator.locator_id
LEFT JOIN 
 ( 
 SELECT SUM(open_quantity) as open_quantity, receving_org_id, item_id_m
 FROM po_all_v pav 
  WHERE receving_org_id IS NOT NULL
 AND open_quantity > 0
 GROUP BY  item_id_m, receving_org_id
 ) po_summary 
ON onhand.item_id_m = po_summary.item_id_m AND po_summary.receving_org_id = onhand.org_id 
LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = onhand.item_id_m AND cic.bom_cost_type='FROZEN'
AND cic.org_id = onhand.org_id,
item

WHERE onhand.item_id_m = item.item_id_m 
AND item.org_id = onhand.org_id
AND item.minmax_min_quantity IS NOT NULL;




CREATE OR REPLACE VIEW fp_kanban_demand_v
(
plan_name, org_id, planning_horizon_days, org, 	 
forecast,forecast_description, 
	 fp_kanban_demand_id, plan_id, item_id_m, quantity,demand_item_id_m,
		 toplevel_demand_item_id_m, demand_type, source,
		 item_number, item_description, 
		top_level_item_number , top_level_item_description,
		 demand_item_number ,demand_item_description,
		 	 created_by, 		 creation_date, 		 last_update_by, 		 last_update_date
)
AS
 SELECT 
mmh.plan_name, mmh.org_id, mmh.planning_horizon_days, org.org, 	 
fh.forecast,fh.description as forecast_description, 
	 fmd.fp_kanban_demand_id, fmd.plan_id, fmd.item_id_m, fmd.quantity,fmd.demand_item_id_m,
		 fmd.toplevel_demand_item_id_m, fmd.demand_type, fmd.source,
		 item.item_number, item.item_description, 
		 item2.item_number as top_level_item_number , item2.item_description as top_level_item_description,
		 item3.item_number as demand_item_number , item3.item_description as demand_item_description,
		 fmd.created_by, 		 fmd.creation_date, 		 fmd.last_update_by, 		 fmd.last_update_date
		 
	
   FROM fp_kanban_demand fmd
	 LEFT JOIN fp_kanban_planner_header mmh ON mmh.fp_kanban_planner_header_id = fmd.plan_id
	 LEFT JOIN fp_forecast_header fh ON fh.fp_forecast_header_id = fmd.source
	 LEFT JOIN item ON item.item_id_m = fmd.item_id_m
	 LEFT JOIN item item2 ON item2.item_id_m = fmd.toplevel_demand_item_id_m
	 LEFT JOIN item item3 ON item3.item_id_m = fmd.demand_item_id_m
	 LEFT JOIN org ON org.org_id = mmh.org_id;
	 
	 
	 
	 
CREATE OR REPLACE VIEW fp_kanban_line_v
(
fp_kanban_line_id,   fp_kanban_header_id,   description,   card_number,   card_status,
supply_status,   kanban_size,   card_type, 
org_id,  kbh_description,   item_id_m,
effective_from,   effective_to,  subinventory_id,   locator_id,
source_type,   supplier_id,   supplier_site_id,   from_org_id,
from_subinventory_id,   from_locator_id,
item_number, item_description, uom_id, list_price, sourcing_rule_id, lead_time,
subinventory,locator,org, bu_org_id
)
AS
SELECT
kbl.fp_kanban_line_id,   kbl.fp_kanban_header_id,   kbl.description,   kbl.card_number,   kbl.card_status,
kbl.supply_status,   kbl.kanban_size,   kbl.card_type, 
kbh.org_id,  kbh.description,   kbh.item_id_m,
kbh.effective_from,   kbh.effective_to,  kbh.subinventory_id,   kbh.locator_id,
kbh.source_type,   kbh.supplier_id,   kbh.supplier_site_id,   kbh.from_org_id,
kbh.from_subinventory_id,   kbh.from_locator_id,
item.item_number, item.item_description, item.uom_id, item.list_price, item.sourcing_rule_id,
IFNULL(item.pre_processing_lt,0) + IFNULL(processing_lt,0) as lead_time,
sub.subinventory, locator.locator, org.org, org.business_org_id 
FROM
fp_kanban_line kbl,
item,
subinventory sub,
org,
fp_kanban_header kbh
LEFT JOIN locator ON locator.locator_id = kbh.locator_id

WHERE kbh.fp_kanban_header_id = kbl.fp_kanban_header_id
AND item.item_id_m = kbh.item_id_m
AND item.org_id = kbh.org_id
AND org.org_id = kbh.org_id
AND sub.subinventory_id = kbh.subinventory_id;




	 CREATE OR REPLACE VIEW minmax_board_v
(onhand_id, item_number, item_description, product_line, org_name, subinventory, locator,
uom_id,onhand, minmax_min_quantity, minmax_max_quantity, open_quantity,
standard_cost, onhand_value,
item_id_m, revision_name, org_id, subinventory_id, subinventory_type,
locator_id, lot_id, serial_id, reservable_onhand, 
transactable_onhand, lot_status, serial_status,  
secondary_uom_id, onhand_status, ef_id, created_by, 
creation_date, last_update_by, last_update_date, min_delta)
AS
SELECT onhand.onhand_id, 
item.item_number, item.item_description, item.product_line,
org.org, subinventory.subinventory, locator.locator,
onhand.uom_id,onhand.onhand, item.minmax_min_quantity, item.minmax_max_quantity, po_summary.open_quantity,
cic.standard_cost, (onhand.onhand * cic.standard_cost) as onhand_value,
onhand.item_id_m, onhand.revision_name, onhand.org_id, onhand.subinventory_id, subinventory.type,
onhand.locator_id, onhand.lot_id, onhand.serial_id, onhand.reservable_onhand, 
onhand.transactable_onhand, onhand.lot_status, onhand.serial_status,  
onhand.secondary_uom_id, onhand.onhand_status, onhand.ef_id, onhand.created_by, 
onhand.creation_date, onhand.last_update_by, onhand.last_update_date,
(onhand.onhand + po_summary.open_quantity - item.minmax_min_quantity)as min_delta
FROM onhand  
LEFT JOIN org ON onhand.org_id = org.org_id
LEFT JOIN subinventory ON onhand.subinventory_id = subinventory.subinventory_id
LEFT JOIN locator ON onhand.locator_id = locator.locator_id
LEFT JOIN 
 ( 
 SELECT SUM(open_quantity) as open_quantity, receving_org_id, item_id_m
 FROM po_all_v pav 
  WHERE receving_org_id IS NOT NULL
 AND open_quantity > 0
 GROUP BY  item_id_m, receving_org_id
 ) po_summary 
ON onhand.item_id_m = po_summary.item_id_m AND po_summary.receving_org_id = onhand.org_id 
LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = onhand.item_id_m AND cic.bom_cost_type='FROZEN'
AND cic.org_id = onhand.org_id,
item

WHERE onhand.item_id_m = item.item_id_m 
AND item.org_id = onhand.org_id
AND item.minmax_min_quantity IS NOT NULL;





CREATE OR REPLACE VIEW fp_minmax_demand_v
(
fp_minmax_header_id, plan_name, org_id, planning_horizon_days, org, 	 
forecast,forecast_description, 
	 fp_minmax_demand_id, plan_id, item_id_m, quantity,demand_item_id_m,
		 toplevel_demand_item_id_m, demand_type, source,
		 item_number, item_description, 
		top_level_item_number , top_level_item_description,
		 demand_item_number ,demand_item_description,
		 	 created_by, 		 creation_date, 		 last_update_by, 		 last_update_date
)
AS
 SELECT 
mmh.fp_minmax_header_id,mmh.plan_name, mmh.org_id, mmh.planning_horizon_days, org.org, 	 
fh.forecast,fh.description as forecast_description, 
	 fmd.fp_minmax_demand_id, fmd.plan_id, fmd.item_id_m, fmd.quantity,fmd.demand_item_id_m,
		 fmd.toplevel_demand_item_id_m, fmd.demand_type, fmd.source,
		 item.item_number, item.item_description, 
		 item2.item_number as top_level_item_number , item2.item_description as top_level_item_description,
		 item3.item_number as demand_item_number , item3.item_description as demand_item_description,
		 fmd.created_by, 		 fmd.creation_date, 		 fmd.last_update_by, 		 fmd.last_update_date
		 
	
   FROM fp_minmax_demand fmd
	 LEFT JOIN fp_minmax_header mmh ON mmh.fp_minmax_header_id = fmd.plan_id
	 LEFT JOIN fp_forecast_header fh ON fh.fp_forecast_header_id = fmd.source
	 LEFT JOIN item ON item.item_id_m = fmd.item_id_m AND item.item_id_m = item.item_id
	 LEFT JOIN item item2 ON item2.item_id_m = fmd.toplevel_demand_item_id_m AND item2.item_id_m = item2.item_id
	 LEFT JOIN item item3 ON item3.item_id_m = fmd.demand_item_id_m AND item3.item_id_m = item3.item_id
	 LEFT JOIN org ON org.org_id = mmh.org_id;
	 
	 
	
CREATE OR REPLACE VIEW fp_mrp_v
(
mrp_name,org_id, org, 
item_number,item_description, demand_item_number, demand_item_description, toplevel_demand_item_number, 
toplevel_demand_item_desc,sourcing_rule_id,
fp_mrp_planned_order_id, fp_mrp_header_id,order_type, order_action, item_id_m, quantity, 
need_by_date,supplier_id,supplier_site_id,demand_item_id_m,toplevel_demand_item_id_m, 
source_type,primary_source_type,source_header_id,source_line_id,
so_number, forecast, sales_order_line
)
AS
 SELECT 
 fmh.mrp_name,fmh.org_id, org.org,
 item.item_number, item.item_description, item2.item_number as demand_item, 
 item2.item_description as demand_item_description, item3.item_number as toplevel_demand_item_number, 
 item3.item_description as toplevel_demand_item_desc, item.sourcing_rule_id,
 fmd.fp_mrp_planned_order_id,  fmd.fp_mrp_header_id, fmd.order_type,  fmd.order_action,fmd.item_id_m,  fmd.quantity, 
 fmd.need_by_date, fmd.supplier_id, fmd.supplier_site_id, fmd.demand_item_id_m, fmd.toplevel_demand_item_id_m, 
 fmd.source_type, fmd.primary_source_type, fmd.source_header_id,fmd.source_line_id,
 ssh.so_number, ffh.forecast, soline.line_number as sales_order_line


FROM fp_mrp_planned_order fmd
LEFT JOIN fp_mrp_header fmh ON fmh.fp_mrp_header_id = fmd.fp_mrp_header_id
LEFT JOIN item  ON item.item_id_m = fmd.item_id_m
LEFT JOIN item item2  ON item2.item_id_m = fmd.demand_item_id_m
LEFT JOIN item item3  ON item3.item_id_m = fmd.toplevel_demand_item_id_m
LEFT JOIN sd_so_header ssh ON ssh.sd_so_header_id = fmd.source_header_id AND fmd.primary_source_type = 'Sales_Order'
LEFT JOIN fp_forecast_header ffh ON ffh.fp_forecast_header_id = fmd.source_header_id AND fmd.primary_source_type = 'Forecast'
LEFT JOIN sd_so_line soline ON soline.sd_so_line_id = fmd.source_line_id AND fmd.primary_source_type = 'Sales_Order'
LEFT JOIN org ON org.org_id = fmh.org_id
ORDER BY item.item_number, fmd.need_by_date;






CREATE OR REPLACE VIEW fp_mrp_demand_v
(
fp_mrp_demand_id, fp_mrp_header_id, mrp_name, org_id, item_id_m, demand_date, quantity,  
demand_item_id_m, toplevel_demand_item_id_m, source_type, primary_source_type, source_header_id, 
source_line_id, item_number, item_description, planner, product_line,
standard_cost, sales_price, purchase_price

)
AS
SELECT fmd.fp_mrp_demand_id, fmd.fp_mrp_header_id,fmh.mrp_name, fmd.org_id, fmd.item_id_m, fmd.demand_date, fmd.quantity,  
fmd.demand_item_id_m, fmd.toplevel_demand_item_id_m, fmd.source_type, fmd.primary_source_type, fmd.source_header_id, 
fmd.source_line_id, item.item_number, item.item_description, item.planner, item.product_line,
cic.standard_cost, cic.sales_price, cic.purchase_price
FROM fp_mrp_demand fmd
LEFT JOIN item ON item.item_id_m = fmd.item_id_m AND item.org_id = fmd.org_id
LEFT JOIN cst_item_cost_v cic ON cic.item_id_m = fmd.item_id_m AND cic.org_id = cic.org_id AND cic.bom_cost_type = 'FROZEN',
fp_mrp_header fmh
WHERE fmh.fp_mrp_header_id = fmd.fp_mrp_header_id;




CREATE OR REPLACE VIEW fp_mrp_existing_supply_v
(
item_id_m, document_type, quantity, supply_date, document_id
)
AS
 						SELECT item.item_id_m as item_id_m, 'PO' as document_type, 
						(pd.quantity - pd.received_quantity)  as quantity, IFNULL(pd.promise_date, pd.need_by_date) as supply_date,
						pd.po_detail_id as document_id
						FROM item,
						po_line pl,
						po_detail pd,
						po_header ph
						WHERE pl.item_id_m = item.item_id_m
						AND pd.po_line_id = pl.po_line_id
						AND pd.po_header_id = ph.po_header_id
						UNION
						SELECT item.item_id_m as item_id_m, 'Requisition' as document_type, 
						prd.quantity  as quantity, IFNULL(prd.promise_date, prd.need_by_date) as supply_date,
						prd.po_requisition_detail_id as document_id
						FROM item,
						po_requisition_line prl,
						po_requisition_detail prd,
						po_requisition_header prh
						WHERE prl.item_id_m = item.item_id_m
						AND prd.po_requisition_line_id = prl.po_requisition_line_id
						AND prd.po_requisition_header_id = prh.po_requisition_header_id
						AND prd.order_number IS NULL
						UNION
							SELECT item.item_id_m as item_id_m, 'Onhand' as document_type, 
							sum(oh.onhand) as quantity, CURDATE() as supply_date,
							oh.onhand_id as document_id
							FROM onhand oh,
               item 
							 WHERE oh.item_id_m = item.item_id_m
							GROUP BY oh.item_id_m
							
           UNION
					 SELECT item.item_id_m as item_id_m, 'WO' as document_type,
					 (wwh.nettable_quantity - IFNULL(wwh.completed_quantity,0) - IFNULL(wwh.scrapped_quantity,0))as quantity,
					 wwh.completion_date as supply_date, wwh.wip_wo_header_id as document_id
					 FROM	wip_wo_header wwh,
					 item 
					 WHERE wwh.item_id_m = item.item_id_m

					 
					 
CREATE OR REPLACE VIEW gl_unposted_journal_lines_v
(
combination, code_combination_id, period_name,
coa_id, sum_total_cr, sum_total_dr,
sum_total_ac_dr, sum_total_ac_cr , ledger_id,
combination_description, gl_journal_line_id, status,
gl_journal_header_id, line_num, line_type, line_description,
reference_type, reference_key_name, reference_key_value , 
coa_structure_id, field1, field2, field3,
field4, field5, field6, field7, field8,
 balance_type, post_date,gl_period_id
)
AS
SELECT  cc.combination, gjl.code_combination_id, gp.period_name,
cc.coa_id, sum(gjl.total_cr), sum(gjl.total_dr),
sum(gjl.total_ac_dr), sum(gjl.total_ac_cr) ,gjh.ledger_id,
cc.description, gjl.gl_journal_line_id,
gjl.gl_journal_header_id, gjl.line_num, gjl.line_type, gjl.description,
gjl.reference_type, gjl.reference_key_name, gjl.reference_key_value , 
cc.coa_structure_id, cc.field1, cc.field2, cc.field3,
cc.field4, cc.field5, cc.field6, cc.field7, cc.field8,
gjh.balance_type, gjh.post_date, gp.gl_period_id

FROM gl_journal_line gjl 
LEFT JOIN gl_journal_header gjh ON gjl.gl_journal_header_id = gjh.gl_journal_header_id
LEFT JOIN gl_period gp ON gp.gl_period_id = gjh.period_id
LEFT JOIN coa_combination cc ON gjl.code_combination_id=cc.coa_combination_id
WHERE gjl.status = 'U'
GROUP BY  gjl.code_combination_id;



CREATE OR REPLACE VIEW inv_interorg_transfer_v
(
inv_intorg_transfer_header_id, order_number, io_order_number, line_number, io_line_number, item_number, status, inv_intorg_transfer_line_id, 
from_org_id, transaction_type_id, to_org_id, carrier, vehicle_number, waybill, uom_id,
from_subinventory_id, from_locator_id, item_id_m, item_description, to_subinventory_id, to_locator_id,  
transaction_quantity, serial_number, lot_number
)
AS
SELECT
ith.inv_intorg_transfer_header_id, ith.order_number, ith.order_number,itl.line_number, itl.line_number,item.item_number, itl.status, itl.inv_intorg_transfer_line_id, 
ith.from_org_id, ith.transaction_type_id, ith.to_org_id, ith.carrier, ith.vehicle_number, ith.waybill, itl.uom_id,
itl.from_subinventory_id, itl.from_locator_id, itl.item_id_m, itl.item_description, itl.to_subinventory_id, itl.to_locator_id,  
itl.transaction_quantity, itl.serial_number, itl.lot_number
FROM inv_intorg_transfer_header ith,
inv_intorg_transfer_line itl,
item
WHERE ith.inv_intorg_transfer_header_id = itl.inv_intorg_transfer_header_id
AND item.item_id_m = itl.item_id_m
AND item.org_id = ith.from_org_id



CREATE OR REPLACE VIEW hr_employee_position_v
(
user_id, username, first_name,last_name,email,hr_employee_id,status,
identification_id,emp_start_date,citizen_number,emp_first_name,emp_last_name,phone, 
emp_email,gender,person_type, org_id, job_id, position_id, expense_ac_id,supervisor_employee_id,
position_name, emp_org_id, hr_approval_limit_header_id, document_type, limit_start_date,
limit_type, limit_range_low, limit_range_high, amount_limit,limit_object, bu_org_id, currency_code
)
AS
 SELECT 
iuser.ino_user_id, iuser.username, iuser.first_name,iuser.last_name,iuser.email,iuser.hr_employee_id,iuser.status,
he.identification_id,he.start_date,he.citizen_number,he.first_name as emp_first_name,he.last_name as emp_last_name,he.phone, 
he.email,he.gender,he.person_type, he.org_id, he.job_id, he.position_id, he.expense_ac_id,he.supervisor_employee_id,
hp.position_name, he.org_id, hala.hr_approval_limit_header_id, hala.document_type, hala.start_date,
hall.limit_type, hall.limit_range_low, hall.limit_range_high, hall.amount_limit,hall.limit_object, halh.bu_org_id, org_v.currency_code
FROM ino_user iuser
LEFT JOIN hr_employee he ON he.hr_employee_id = iuser.hr_employee_id
LEFT JOIN hr_position hp ON hp.hr_position_id = he.position_id
LEFT JOIN hr_approval_limit_assign hala ON he.position_id = hala.position_id
LEFT JOIN hr_approval_limit_line hall ON  hala.hr_approval_limit_header_id =  hall.hr_approval_limit_header_id
LEFT JOIN hr_approval_object hao ON  hao.hr_approval_object_id =  hall.limit_object
LEFT JOIN hr_approval_limit_header halh ON hall.hr_approval_limit_header_id = halh.hr_approval_limit_header_id
LEFT JOIN org_v ON org_v.org_id =  halh.bu_org_id