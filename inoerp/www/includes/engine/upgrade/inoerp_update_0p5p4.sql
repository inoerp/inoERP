CREATE TABLE `address` (
  `address_id` int(10) UNSIGNED NOT NULL,
  `type` varchar(20) DEFAULT 'both',
  `address_name` varchar(50) DEFAULT NULL,
  `mdm_tax_region_id` int(12) DEFAULT NULL,
  `description` varchar(200) DEFAULT NULL,
  `phone` varchar(50) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `website` varchar(200) DEFAULT NULL,
  `address` text,
  `country` varchar(40) DEFAULT NULL,
  `postal_code` varchar(20) DEFAULT NULL,
  `default_cb` tinyint(1) DEFAULT NULL,
  `status` varchar(20) DEFAULT NULL,
  `usage_type` varchar(25) DEFAULT NULL,
  `rev_number` int(10) DEFAULT NULL,
  `created_by` int(12) NOT NULL,
  `creation_date` datetime DEFAULT NULL,
  `last_update_by` int(12) NOT NULL,
  `last_update_date` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Structure for view `po_blanket_v`
--
DROP TABLE IF EXISTS `po_blanket_v`;

CREATE ALGORITHM=UNDEFINED DEFINER=`root`@`localhost` SQL SECURITY DEFINER VIEW `po_blanket_v`  AS  select `po_header`.`po_header_id` AS `po_header_id`,`po_header`.`bu_org_id` AS `bu_org_id`,`po_header`.`po_type` AS `po_type`,`po_header`.`po_number` AS `po_number`,`po_header`.`release_number` AS `release_number`,`po_header`.`supplier_id` AS `supplier_id`,`po_header`.`supplier_site_id` AS `supplier_site_id`,`po_header`.`buyer` AS `buyer`,`po_header`.`currency` AS `currency`,`po_header`.`header_amount` AS `header_amount`,`po_header`.`po_status` AS `po_status`,`po_header`.`payment_term_id` AS `payment_term_id`,`supplier`.`supplier_name` AS `supplier_name`,`supplier`.`supplier_number` AS `supplier_number`,`supplier_site`.`supplier_site_name` AS `supplier_site_name`,`supplier_site`.`supplier_site_number` AS `supplier_site_number`,`payment_term`.`payment_term` AS `payment_term`,`payment_term`.`description` AS `payment_term_description`,`po_header`.`agreement_start_date` AS `agreement_start_date`,`po_header`.`agreement_end_date` AS `agreement_end_date`,`po_line`.`po_line_id` AS `po_line_id`,`po_line`.`line_type` AS `line_type`,`po_line`.`line_number` AS `po_line_number`,`po_line`.`item_id_m` AS `item_id_m`,`po_line`.`item_description` AS `item_description`,`po_line`.`line_description` AS `line_description`,`po_line`.`line_quantity` AS `line_quantity`,`po_line`.`unit_price` AS `unit_price`,`po_line`.`line_price` AS `line_price`,`item`.`item_number` AS `item_number`,`item`.`uom_id` AS `uom_id`,`item`.`item_status` AS `item_status`,`po_detail`.`po_detail_id` AS `po_detail_id`,`po_detail`.`shipment_number` AS `shipment_number`,`po_line`.`receving_org_id` AS `receving_org_id`,`po_detail`.`subinventory_id` AS `subinventory_id`,`po_detail`.`locator_id` AS `locator_id`,`po_detail`.`requestor` AS `requestor`,`po_detail`.`quantity` AS `quantity`,ifnull(`po_detail`.`received_quantity`,0) AS `received_quantity`,(`po_detail`.`quantity` - ifnull(`po_detail`.`received_quantity`,0)) AS `open_quantity`,`po_detail`.`need_by_date` AS `need_by_date`,`po_detail`.`promise_date` AS `promise_date`,`po_detail`.`accepted_quantity` AS `accepted_quantity`,`po_detail`.`delivered_quantity` AS `delivered_quantity`,`po_detail`.`invoiced_quantity` AS `invoiced_quantity`,`po_detail`.`paid_quantity` AS `paid_quantity`,`po_detail`.`charge_ac_id` AS `charge_ac_id`,`po_detail`.`accrual_ac_id` AS `accrual_ac_id`,`po_detail`.`budget_ac_id` AS `budget_ac_id`,`po_detail`.`ppv_ac_id` AS `ppv_ac_id`,`org`.`org` AS `receving_org`,`po_header`.`created_by` AS `created_by`,`po_header`.`creation_date` AS `creation_date`,`po_header`.`last_update_by` AS `last_update_by`,`po_header`.`last_update_date` AS `last_update_date` from (((((((`po_header` left join `supplier` on((`po_header`.`supplier_id` = `supplier`.`supplier_id`))) left join `supplier_site` on((`po_header`.`supplier_site_id` = `supplier_site`.`supplier_site_id`))) left join `payment_term` on((`po_header`.`payment_term_id` = `payment_term`.`payment_term_id`))) left join `po_line` on((`po_header`.`po_header_id` = `po_line`.`po_header_id`))) left join `item` on(((`po_line`.`item_id_m` = `item`.`item_id_m`) and (`item`.`org_id` = `po_line`.`receving_org_id`)))) left join `po_detail` on((`po_line`.`po_line_id` = `po_detail`.`po_line_id`))) left join `org` on((`po_line`.`receving_org_id` = `org`.`org_id`))) where (`po_header`.`po_type` in ('BLANKET','BLANKET_RELEASE')) ;

-- --------------------------------------------------------