-- phpMyAdmin SQL Dump
-- version 3.4.11.1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jul 01, 2013 at 01:06 PM
-- Server version: 5.0.96
-- PHP Version: 5.2.17

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `inoideas_erp`
--

-- --------------------------------------------------------

--
-- Table structure for table `address`
--

CREATE TABLE IF NOT EXISTS `address` (
  `address_id` int(10) unsigned NOT NULL auto_increment,
  `type` varchar(20) default 'both',
  `name` varchar(50) NOT NULL,
  `description` varchar(200) default NULL,
  `phone` varchar(50) default NULL,
  `email` varchar(100) default NULL,
  `website` varchar(200) default NULL,
  `value` text,
  `country` varchar(40) default NULL,
  `postal_code` varchar(20) default NULL,
  `ef_id` int(12) default NULL,
  `status` varchar(20) default NULL,
  `rev_enabled` varchar(20) default NULL,
  `rev_number` int(10) default NULL,
  `created_by` varchar(40) NOT NULL default '',
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(40) NOT NULL default '',
  `last_update_date` varchar(50) default NULL,
  PRIMARY KEY  (`address_id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=84 ;

--
-- Dumping data for table `address`
--

INSERT INTO `address` (`address_id`, `type`, `name`, `description`, `phone`, `email`, `website`, `value`, `country`, `postal_code`, `ef_id`, `status`, `rev_enabled`, `rev_number`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(79, 'INTERNATIONAL', 'TEST11', 'Desc1111a', NULL, NULL, NULL, '\\r\\n                 \\\\r\\\\n                 office_India\\\\\\\\r\\\\\\\\nnnasdsa', 'india', '24324', 0, '', '', 0, 'inoerp', '', 'inoerp', '15-06-13 16:21:50'),
(80, 'INTERNATIONAL', 'inoERP_ENTERPRISE1', 'Address of inoerp Enterprise & Legal org', '', '', '', '<p>14A, Delgoiee Road<br /><br />Purabolaa, Mahaleji Road</p>\r\n<p><strong>Mumbai</strong></p>', 'India', '232111', 1, 'enabled', 'enabled', 1, 'inoerp', '', 'inoerp', '17-06-13 08:02:47'),
(81, 'INTERNATIONAL', 'ORG_ADDRESS', 'Address for org', NULL, NULL, NULL, 'inoideas Pvt Ltd\r\n26262A, Archad road\r\nSvahah, NA', 'India', '213154', 1, 'enabled', 'enabled', 1, 'inoerp', '', 'inoerp', '15-06-13 19:10:52'),
(82, 'INTERNATIONAL', 'vcvc43', 'b vjbjv hjjjbj', '23213213', '', '', 'fgdhc\r\n789798\r\nvhjhjjbk', 'india', '98797897', 0, '', '', 0, 'inoerp', '', 'inoerp', '15-06-13 19:41:45'),
(83, 'INTERNATIONAL', 'TEST20', 'TEST20Desc', '617-1919-191991', 'nishsisi@haaa.com', 'http://www.asdjsakdsa-asdjdskl.com', '<p>81 a, gimmanbi road</p>\r\n<p>867d- wqljnjsa ,lsad sanms</p>', 'USA', '8679808', 1, 'enabled', 'enabled', 1, 'inoerp', '', 'inoerp', '17-06-13 12:10:28');

-- --------------------------------------------------------

--
-- Table structure for table `ap_payment_terms`
--

CREATE TABLE IF NOT EXISTS `ap_payment_terms` (
  `term_id` int(12) NOT NULL auto_increment,
  `term_name` varchar(12) default NULL,
  `term_description` varchar(50) NOT NULL,
  `end_date` date NOT NULL,
  PRIMARY KEY  (`term_id`),
  UNIQUE KEY `term_name` (`term_name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `ap_payment_terms`
--

INSERT INTO `ap_payment_terms` (`term_id`, `term_name`, `term_description`, `end_date`) VALUES
(1, 'NET 30', 'Payment in 30 dates', '0000-00-00'),
(2, 'NET 45', 'Payment in 45 days', '0000-00-00'),
(3, 'Immediate', 'Payment due Immediately', '0000-00-00');

-- --------------------------------------------------------

--
-- Table structure for table `business_org`
--

CREATE TABLE IF NOT EXISTS `business_org` (
  `business_id` int(12) NOT NULL auto_increment,
  `business_org_type` varchar(50) default NULL,
  `manager` varchar(50) default NULL,
  `ef_id` int(12) default NULL,
  `rev_enabled` varchar(50) default NULL,
  `rev_number` int(12) default NULL,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) NOT NULL,
  `last_update_date` varchar(50) NOT NULL,
  PRIMARY KEY  (`business_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Dumping data for table `business_org`
--

INSERT INTO `business_org` (`business_id`, `business_org_type`, `manager`, `ef_id`, `rev_enabled`, `rev_number`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 09:49:12', 'inoerp', '01-07-2013 09:49:12'),
(2, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 09:52:19', 'inoerp', '01-07-2013 09:52:19'),
(3, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 09:53:12', 'inoerp', '01-07-2013 09:53:12'),
(4, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 09:53:44', 'inoerp', '01-07-2013 09:53:44'),
(5, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 09:57:32', 'inoerp', '01-07-2013 09:57:32'),
(6, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 11:44:02', 'inoerp', '01-07-2013 11:44:02'),
(7, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 11:44:23', 'inoerp', '01-07-2013 11:44:23');

-- --------------------------------------------------------

--
-- Table structure for table `coa`
--

CREATE TABLE IF NOT EXISTS `coa` (
  `coa_id` int(12) NOT NULL auto_increment,
  `structure` varchar(200) NOT NULL,
  `name` varchar(200) NOT NULL,
  `description` varchar(200) default NULL,
  `balancing` varchar(100) NOT NULL,
  `cost_center` varchar(100) NOT NULL,
  `natural_account` varchar(100) NOT NULL,
  `inter_company` varchar(100) NOT NULL,
  `segment1` varchar(100) NOT NULL default 'NU',
  `segment2` varchar(100) NOT NULL default 'NU',
  `segment3` varchar(100) NOT NULL default 'NU',
  `segment4` varchar(100) NOT NULL default 'NU',
  `coa_sequence` varchar(250) NOT NULL,
  `ef_id` int(12) default NULL,
  `status` varchar(50) default NULL,
  `rev_enabled` varchar(50) default NULL,
  `rev_number` int(12) default NULL,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) NOT NULL,
  `last_update_date` varchar(50) NOT NULL,
  PRIMARY KEY  (`coa_id`),
  UNIQUE KEY `value` (`name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=8 ;

--
-- Dumping data for table `coa`
--

INSERT INTO `coa` (`coa_id`, `structure`, `name`, `description`, `balancing`, `cost_center`, `natural_account`, `inter_company`, `segment1`, `segment2`, `segment3`, `segment4`, `coa_sequence`, `ef_id`, `status`, `rev_enabled`, `rev_number`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, '82', 'ino_corp_coa', 'ino_corp_coa1', 'LEGAL_UNIT', 'COST_CENTER', 'ACCOUNT', 'INTERCOMPANY', '', '', '', '', 'LEGAL_UNIT-COST_CENTER-ACCOUNT-INTERCOMPANY----', 2, 'enabled', 'disabled', 1, 'inoerp', '19-06-2013 10:17:49', 'inoerp', '19-06-13 17:21:35'),
(2, '82', 'ino_erp_coa1', 'ino ERP COA', 'LEGAL_UNIT', 'COST_CENTER', 'ACCOUNT', 'INTERCOMPANY', '', '', '', '', 'LEGAL_UNIT-LEGAL_UNIT-LEGAL_UNIT-LEGAL_UNIT-LEGAL_UNIT-LEGAL_UNIT-LEGAL_UNIT-LEGAL_UNIT', 1, 'enabled', 'enabled', 1, 'inoerp', '19-06-2013 11:32:36', 'inoerp', '28-06-13 05:14:00'),
(3, '80', 'ino_enterprise_01', 'COA of ino enterprise', 'SEGMENT1', 'SEGMENT2', 'SEGMENT3', 'SEGMENT4', 'SEGMENT5', 'SEGMENT6', 'SEGMENT7', 'SEGMENT8', '', 1, 'enabled', 'enabled', 1, 'inoerp', '19-06-2013 14:02:07', 'inoerp', '19-06-2013 14:02:07'),
(4, '82', 'TEST01', 'Ino Corp Final COA', 'LEGAL_UNIT', 'COST_CENTER', 'ACCOUNT', 'INTERCOMPANY', 'BUSINESS_UNIT', 'PRODUCT_CODE', 'NU', 'NU', 'LEGAL_UNIT-BUSINESS_UNIT-COST_CENTER-ACCOUNT-PRODUCT_CODE-INTERCOMPANY-NU-NU', 1, 'enabled', 'enabled', 0, 'inoerp', '19-06-2013 14:15:01', 'inoerp', '26-06-13 15:53:14'),
(5, '82', 'TEST02', 'TEST02 Desc', 'LEGAL_UNIT', 'BUSINESS_UNIT', 'ACCOUNT', 'INTERCOMPANY', 'BUSINESS_UNIT', 'PRODUCT_CODE', 'NU', 'NU', 'LEGAL_UNIT-BUSINESS_UNIT-ACCOUNT-INTERCOMPANY-PRODUCT_CODE-LEGAL_UNIT-LEGAL_UNIT-LEGAL_UNIT', 0, '', '', 0, 'inoerp', '19-06-2013 17:30:57', 'inoerp', '22-06-13 16:32:40'),
(6, '82', 'TEST03', 'TEST03', 'LEGAL_UNIT', 'COST_CENTER', 'ACCOUNT', 'INTERCOMPANY', 'BUSINESS_UNIT', 'PRODUCT_CODE', 'NU', 'NU', 'LEGAL_UNIT-BUSINESS_UNIT-COST_CENTER-ACCOUNT-PRODUCT_CODE-INTERCOMPANY-NU-NU', 0, '', '', 0, 'inoerp', '19-06-2013 17:32:32', 'inoerp', '19-06-13 17:33:10'),
(7, '82', 'INO_CROP_01', 'Ino corp COA 01', 'LEGAL_UNIT', 'COST_CENTER', 'ACCOUNT', 'INTERCOMPANY', 'BUSINESS_UNIT', 'PRODUCT_CODE', 'NU', 'NU', 'LEGAL_UNIT-BUSINESS_UNIT-COST_CENTER-ACCOUNT-PRODUCT_CODE-INTERCOMPANY-NU-NU', 0, 'enabled', 'enabled', 0, 'inoerp', '28-06-2013 05:15:45', 'inoerp', '28-06-13 05:16:35');

-- --------------------------------------------------------

--
-- Table structure for table `coa_combination`
--

CREATE TABLE IF NOT EXISTS `coa_combination` (
  `coa_combination_id` int(12) NOT NULL auto_increment,
  `coa_id` int(12) NOT NULL,
  `balancing` varchar(100) NOT NULL,
  `cost_center` varchar(100) NOT NULL,
  `natural_account` varchar(100) NOT NULL,
  `inter_company` varchar(100) NOT NULL,
  `segment1` varchar(100) default NULL,
  `segment2` varchar(100) default NULL,
  `segment3` varchar(100) default NULL,
  `segment4` varchar(100) default NULL,
  `combination` varchar(256) NOT NULL,
  `description` varchar(200) default NULL,
  `ef_id` int(12) default NULL,
  `status` varchar(50) default NULL,
  `rev_enabled` varchar(50) default NULL,
  `rev_number` int(12) default NULL,
  `effective_start_date` varchar(200) default NULL,
  `effective_end_date` varchar(200) default NULL,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) NOT NULL,
  `last_update_date` varchar(50) NOT NULL,
  PRIMARY KEY  (`coa_combination_id`),
  KEY `coa_id` (`coa_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=30 ;

--
-- Dumping data for table `coa_combination`
--

INSERT INTO `coa_combination` (`coa_combination_id`, `coa_id`, `balancing`, `cost_center`, `natural_account`, `inter_company`, `segment1`, `segment2`, `segment3`, `segment4`, `combination`, `description`, `ef_id`, `status`, `rev_enabled`, `rev_number`, `effective_start_date`, `effective_end_date`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, 1, '123', '22', '232', '22', '', '', '', '', '', '', 0, '', '', 0, '', '', 'inoerp', '27-06-2013 12:32:30', 'inoerp', '27-06-2013 12:32:30'),
(2, 4, '1000', '1212', '1222', '2311', '', '', '', '', '1000-1212-1222-2311', 'TEST02', 0, 'enabled', '', 0, '', '', 'inoerp', '28-06-2013 01:58:56', 'inoerp', '28-06-13 02:02:58'),
(3, 4, '1000', '1212', '1222', '2312', '', '', '', '', '1000-1212-1222-2312', 'TEST03', 0, 'enabled', '', 0, '', '', 'inoerp', '28-06-2013 02:02:58', 'inoerp', '28-06-2013 02:02:58'),
(4, 1, '121', '342', '121', '12', '', '', '', '', '121-342-121-12', 'TEST01', 0, 'enabled', '', 0, '', '', 'inoerp', '28-06-2013 03:23:01', 'inoerp', '28-06-2013 03:23:01'),
(5, 6, '100', '111', '123', '23', '', '', '', '', '100-111-123-23', 'TEST01', 0, 'enabled', '', 0, '', '', 'inoerp', '28-06-2013 03:28:56', 'inoerp', '28-06-2013 03:28:56'),
(6, 6, '100', '111', '123', '24', '', '', '', '', '100-111-123-24', 'TEST02', 0, '', '', 0, '', '', 'inoerp', '28-06-2013 03:28:56', 'inoerp', '28-06-2013 03:28:56'),
(29, 7, '001', '3300', '9100', '001', '100', '001', '', '', '001-100-3300-9100-001-001', 'ACCOUNT10', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(28, 7, '001', '3300', '31010', '001', '100', '001', '', '', '001-100-3300-31010-001-001', 'ACCOUNT9', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(27, 7, '001', '3300', '28100', '001', '100', '001', '', '', '001-100-3300-28100-001-001', 'ACCOUNT8', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(26, 7, '001', '3300', '29500', '001', '100', '001', '', '', '001-100-3300-29500-001-001', 'ACCOUNT7', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(25, 7, '001', '0000', '40100', '001', '100', '001', '', '', '001-100-0000-40100-001-001', 'ACCOUNT6', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(24, 7, '001', '0000', '51000', '001', '100', '001', '', '', '001-100-0000-51000-001-001', 'ACCOUNT5', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(23, 7, '001', '0000', '21000', '001', '100', '001', '', '', '001-100-0000-21000-001-001', 'ACCOUNT4', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(22, 7, '001', '0000', '17000', '001', '100', '001', '', '', '001-100-0000-17000-001-001', 'ACCOUNT3', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(21, 7, '001', '0000', '13100', '001', '100', '001', '', '', '001-100-0000-13100-001-001', 'ACCOUNT2', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:39:25', 'inoerp', '29-06-2013 08:39:25'),
(20, 7, '001', '0000', '10100', '001', '100', '001', '', '', '001-100-0000-10100-001-001', 'ACCOUNT1', 0, 'enabled', '', 0, '', '', 'inoerp', '29-06-2013 08:34:11', 'inoerp', '29-06-13 08:39:25');

-- --------------------------------------------------------

--
-- Table structure for table `coa_segment_values`
--

CREATE TABLE IF NOT EXISTS `coa_segment_values` (
  `coa_segment_values_id` int(12) unsigned NOT NULL auto_increment,
  `coa_id` int(12) NOT NULL,
  `coa_segments` varchar(50) NOT NULL,
  `account_type` varchar(50) default NULL,
  `segment_code` varchar(50) NOT NULL,
  `description` varchar(255) default NULL,
  `efid` int(12) default NULL,
  `status` varchar(50) default 'disabled',
  `rev_enabled` varchar(50) default 'disabled',
  `rev_number` int(10) default NULL,
  `effective_start_date` varchar(50) default NULL,
  `effective_end_date` varchar(50) default NULL,
  `created_by` varchar(40) NOT NULL default '',
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(40) NOT NULL default '',
  `last_update_date` varchar(50) default NULL,
  PRIMARY KEY  (`coa_segment_values_id`),
  KEY `coa_id` (`coa_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=90 ;

--
-- Dumping data for table `coa_segment_values`
--

INSERT INTO `coa_segment_values` (`coa_segment_values_id`, `coa_id`, `coa_segments`, `account_type`, `segment_code`, `description`, `efid`, `status`, `rev_enabled`, `rev_number`, `effective_start_date`, `effective_end_date`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, 3, '', 'SEGMENT1', '002', 'India', NULL, '', '', 0, NULL, NULL, 'inoerp', '23-06-2013 04:17:21', 'inoerp', '23-06-2013 04:17:21'),
(43, 1, 'ACCOUNT', 'L', 'TEST02', 'TEST02', NULL, 'disabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 10:33:25', 'inoerp', '27-06-13 12:01:53'),
(25, 1, 'ACCOUNT', 'L', '20300', 'Liab1', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 08:25:38', 'inoerp', '27-06-13 12:01:53'),
(4, 1, 'LEGAL_UNIT', '', '010', 'India', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 05:18:33', 'inoerp', '25-06-13 11:02:56'),
(5, 1, 'LEGAL_UNIT', '', '011', 'US', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 05:18:33', 'inoerp', '25-06-13 11:02:56'),
(24, 1, 'LEGAL_UNIT', '', '016', 'France', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '24-06-2013 15:02:21', 'inoerp', '25-06-13 11:02:56'),
(59, 7, 'LEGAL_UNIT', '', '001', 'US Corp.', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:17:52', 'inoerp', '28-06-13 13:28:29'),
(53, 1, 'INTERCOMPANY', '', '0001', 'First', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 11:03:55', 'inoerp', '25-06-13 11:05:06'),
(10, 1, 'ACCOUNT', 'A', '10000', 'Cash in Bank', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 17:13:56', 'inoerp', '27-06-13 12:01:53'),
(11, 1, 'ACCOUNT', 'A', '10100', 'Receviables', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 17:13:56', 'inoerp', '27-06-13 12:01:53'),
(12, 1, 'ACCOUNT', 'A', '10600', 'Petty Cash', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 17:17:14', 'inoerp', '27-06-13 12:01:53'),
(13, 1, 'ACCOUNT', 'A', '10800', 'Inventory', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 17:17:53', 'inoerp', '27-06-13 12:01:53'),
(14, 1, 'ACCOUNT', 'A', '10400', 'Supplies', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 17:36:49', 'inoerp', '27-06-13 12:01:53'),
(15, 1, 'ACCOUNT', 'L', '20100', 'Notes Payable - Credit Line #1', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 17:49:59', 'inoerp', '27-06-13 12:01:53'),
(16, 1, 'ACCOUNT', 'L', '20200', 'Notes Payable - Credit Line #2', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '23-06-2013 17:49:59', 'inoerp', '27-06-13 12:01:53'),
(27, 1, 'ACCOUNT', 'A', '10400', 'asset', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 08:26:36', 'inoerp', '27-06-13 12:01:53'),
(30, 1, 'LEGAL_UNIT', '', '020', 'Global', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 08:35:45', 'inoerp', '25-06-13 11:02:56'),
(56, 1, 'BUSINESS_UNIT', '', '0001', 'IT Solution', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 11:05:49', 'inoerp', '25-06-2013 11:05:49'),
(51, 1, 'ACCOUNT', 'C', 'TEST20', 'TEST20', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 11:02:24', 'inoerp', '27-06-13 12:01:53'),
(55, 1, 'INTERCOMPANY', '', '0003', 'Third', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 11:05:06', 'inoerp', '25-06-2013 11:05:06'),
(47, 1, 'ACCOUNT', 'C', 'TEST06', 'TEST06', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 10:43:42', 'inoerp', '27-06-13 12:01:53'),
(52, 1, 'LEGAL_UNIT', '', '021', 'Ghana', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 11:02:56', 'inoerp', '25-06-2013 11:02:56'),
(42, 1, 'ACCOUNT', 'A', 'TEST01', 'TEST01', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 10:25:38', 'inoerp', '27-06-13 12:01:53'),
(54, 1, 'INTERCOMPANY', '', '0002', 'Second', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 11:05:06', 'inoerp', '25-06-2013 11:05:06'),
(50, 1, 'ACCOUNT', 'X', 'TEST12', 'TEST12', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '25-06-2013 10:54:42', 'inoerp', '27-06-13 12:01:53'),
(57, 1, 'ACCOUNT', 'A', 'TEST02', 'TEST02', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '26-06-2013 07:29:02', 'inoerp', '27-06-13 12:01:53'),
(58, 1, 'ACCOUNT', 'C', 'TEST99', 'TEST02', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '27-06-2013 12:01:32', 'inoerp', '27-06-13 12:01:53'),
(60, 7, 'LEGAL_UNIT', '', '002', 'UK Corp.', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:17:52', 'inoerp', '28-06-13 13:28:29'),
(61, 7, 'LEGAL_UNIT', '', '003', 'India', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:17:52', 'inoerp', '28-06-13 13:28:29'),
(62, 7, 'BUSINESS_UNIT', '', '001', 'Enginee', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:18:45', 'inoerp', '29-06-13 08:05:57'),
(63, 7, 'BUSINESS_UNIT', '', '002', 'IT Consulting', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:18:45', 'inoerp', '29-06-13 08:05:57'),
(64, 7, 'BUSINESS_UNIT', '', '003', 'Repair', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:18:45', 'inoerp', '29-06-13 08:05:57'),
(65, 7, 'COST_CENTER', '', '0001', 'HR', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:19:55', 'inoerp', '29-06-13 08:20:30'),
(66, 7, 'COST_CENTER', '', '0002', 'IT', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:19:55', 'inoerp', '29-06-13 08:20:30'),
(67, 7, 'COST_CENTER', '', '0003', 'Production', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:19:55', 'inoerp', '29-06-13 08:20:30'),
(68, 7, 'COST_CENTER', '', '0004', 'Others', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:19:55', 'inoerp', '29-06-13 08:20:30'),
(69, 7, 'ACCOUNT', 'A', '10100', 'Cash - Regular Checking', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:21:50', 'inoerp', '29-06-13 08:13:02'),
(80, 7, 'ACCOUNT', 'A', '13100', 'Inventory', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(71, 7, 'PRODUCT_CODE', '', '001', 'BIOS01', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:22:27', 'inoerp', '28-06-2013 05:22:27'),
(72, 7, 'PRODUCT_CODE', '', '002', 'BIOS02', NULL, '', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:22:27', 'inoerp', '28-06-2013 05:22:27'),
(73, 7, 'INTERCOMPANY', '', '001', 'US Corp.', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 05:23:01', 'inoerp', '28-06-2013 05:23:01'),
(74, 7, 'LEGAL_UNIT', '', '100', 'US Corp1.', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 09:43:22', 'inoerp', '28-06-13 13:28:29'),
(75, 7, 'LEGAL_UNIT', '', '200', 'India 2', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 09:43:22', 'inoerp', '28-06-13 13:28:29'),
(76, 7, 'COST_CENTER', '', '200', 'HR1', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 11:55:12', 'inoerp', '29-06-13 08:20:30'),
(77, 7, 'BUSINESS_UNIT', '', '100', 'Corporate', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 11:59:56', 'inoerp', '29-06-13 08:05:57'),
(78, 7, 'BUSINESS_UNIT', '', '110', 'Enginee1', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '28-06-2013 13:29:13', 'inoerp', '29-06-13 08:05:57'),
(79, 7, 'COST_CENTER', '', '0000', 'Default', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:06:47', 'inoerp', '29-06-13 08:20:30'),
(81, 7, 'ACCOUNT', 'A', '17000', 'Fixed Asset', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(82, 7, 'ACCOUNT', 'L', '21000', 'Accounts-Payable', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(83, 7, 'ACCOUNT', 'E', '29500', 'Owners Equity', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(84, 7, 'ACCOUNT', 'E', '28100', 'Retained Earning', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(85, 7, 'ACCOUNT', 'I', '31010', 'Sales', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(86, 7, 'ACCOUNT', 'A', '51000', 'COGS', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(87, 7, 'ACCOUNT', 'A', '40100', 'Marketing Exp', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(88, 7, 'ACCOUNT', 'X', '9100', 'Gain Loss', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:13:02', 'inoerp', '29-06-2013 08:13:02'),
(89, 7, 'COST_CENTER', '', '3300', 'Default', NULL, 'enabled', '', 0, NULL, NULL, 'inoerp', '29-06-2013 08:20:30', 'inoerp', '29-06-2013 08:20:30');

-- --------------------------------------------------------

--
-- Table structure for table `enterprise`
--

CREATE TABLE IF NOT EXISTS `enterprise` (
  `enterprise_id` int(12) NOT NULL auto_increment,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) default NULL,
  `last_update_date` varchar(50) default NULL,
  PRIMARY KEY  (`enterprise_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=36 ;

--
-- Dumping data for table `enterprise`
--

INSERT INTO `enterprise` (`enterprise_id`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(35, 'inoerp', '01-07-2013 03:17:53', 'inoerp', '01-07-2013 03:17:53'),
(34, 'inoerp', '01-07-2013 01:18:57', 'inoerp', '01-07-2013 01:18:57'),
(33, 'inoerp', '16-06-2013 06:31:44', 'inoerp', '16-06-2013 06:31:44'),
(32, 'inoerp', '15-06-2013 08:12:44', 'inoerp', '15-06-2013 08:12:44'),
(24, 'inoerp', '13-06-2013 09:27:47', 'inoerp', '13-06-2013 09:27:47'),
(25, 'inoerp', '13-06-2013 10:38:19', 'inoerp', '13-06-2013 10:38:19'),
(26, 'inoerp', '13-06-2013 13:49:00', 'inoerp', '13-06-2013 13:49:00'),
(27, 'inoerp', '13-06-2013 13:52:45', 'inoerp', '13-06-2013 13:52:45'),
(28, 'inoerp', '13-06-2013 13:57:11', 'inoerp', '13-06-2013 13:57:11'),
(29, 'inoerp', '14-06-2013 11:36:47', 'inoerp', '14-06-13 12:08:21'),
(31, 'inoerp', '14-06-2013 15:00:51', 'inoerp', '14-06-2013 15:00:51');

-- --------------------------------------------------------

--
-- Table structure for table `inventory_org`
--

CREATE TABLE IF NOT EXISTS `inventory_org` (
  `inventory_id` int(12) NOT NULL auto_increment,
  `master_org` int(12) default NULL,
  `calendar` varchar(50) default NULL,
  `locator_control` varchar(50) default NULL,
  `allow_negative_balance` varchar(50) default NULL,
  `costing_org` varchar(50) NOT NULL,
  `costing_method` varchar(50) NOT NULL,
  `transfer_to_gl` varchar(50) NOT NULL,
  `default_cost_group` varchar(50) default NULL,
  `material_ac` varchar(256) NOT NULL,
  `material_oh_ac` varchar(256) default NULL,
  `overhead_ac` varchar(256) default NULL,
  `resource_ac` varchar(256) default NULL,
  `expense_ac` varchar(256) default NULL,
  `lot_uniqueness` varchar(50) default NULL,
  `lot_generation` varchar(50) default NULL,
  `lot_prefix` varchar(50) default NULL,
  `lot_starting_number` varchar(50) default NULL,
  `atp` varchar(50) default NULL,
  `picking_rule` varchar(50) default NULL,
  `sourcing_rule` varchar(50) default NULL,
  `inter_org_ppv_ac` varchar(256) default NULL,
  `inter_org_receivable_ac` varchar(256) default NULL,
  `inter_org_payable_ac` varchar(256) default NULL,
  `inter_org_intransit_ac` varchar(256) default NULL,
  `inv_ap_accrual_ac` varchar(256) NOT NULL,
  `inv_ap_exp_accrual_ac` varchar(256) default NULL,
  `inv_ppv_ac` varchar(256) default NULL,
  `inv_ipv_ac` varchar(256) default NULL,
  `sales_ac` varchar(256) NOT NULL,
  `cogs_ac` varchar(256) NOT NULL,
  `deffered_cogs_Ac` varchar(256) default NULL,
  `ef_id` int(12) default NULL,
  `rev_enabled` varchar(50) default NULL,
  `rev_number` int(12) default NULL,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) NOT NULL,
  `last_update_date` varchar(50) NOT NULL,
  PRIMARY KEY  (`inventory_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=2 ;

--
-- Dumping data for table `inventory_org`
--

INSERT INTO `inventory_org` (`inventory_id`, `master_org`, `calendar`, `locator_control`, `allow_negative_balance`, `costing_org`, `costing_method`, `transfer_to_gl`, `default_cost_group`, `material_ac`, `material_oh_ac`, `overhead_ac`, `resource_ac`, `expense_ac`, `lot_uniqueness`, `lot_generation`, `lot_prefix`, `lot_starting_number`, `atp`, `picking_rule`, `sourcing_rule`, `inter_org_ppv_ac`, `inter_org_receivable_ac`, `inter_org_payable_ac`, `inter_org_intransit_ac`, `inv_ap_accrual_ac`, `inv_ap_exp_accrual_ac`, `inv_ppv_ac`, `inv_ipv_ac`, `sales_ac`, `cogs_ac`, `deffered_cogs_Ac`, `ef_id`, `rev_enabled`, `rev_number`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, NULL, NULL, NULL, NULL, '', '', '', NULL, '', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, '', NULL, NULL, NULL, '', '', NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 12:53:19', 'inoerp', '01-07-2013 12:53:19');

-- --------------------------------------------------------

--
-- Table structure for table `legal_org`
--

CREATE TABLE IF NOT EXISTS `legal_org` (
  `legal_id` int(12) NOT NULL auto_increment,
  `legal_org_type` varchar(50) default NULL,
  `registration_number` varchar(50) default NULL,
  `place_of_registration` varchar(50) default NULL,
  `country_of_registration` varchar(100) default NULL,
  `identification_number` varchar(50) default NULL,
  `ein_tin_tan` varchar(50) default NULL,
  `ledger_id` int(12) default NULL,
  `balancing_segments` text,
  `ef_id` int(12) default NULL,
  `rev_enabled` varchar(50) default NULL,
  `rev_number` int(12) default NULL,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) NOT NULL,
  `last_update_date` varchar(50) NOT NULL,
  PRIMARY KEY  (`legal_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=5 ;

--
-- Dumping data for table `legal_org`
--

INSERT INTO `legal_org` (`legal_id`, `legal_org_type`, `registration_number`, `place_of_registration`, `country_of_registration`, `identification_number`, `ein_tin_tan`, `ledger_id`, `balancing_segments`, `ef_id`, `rev_enabled`, `rev_number`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 02:29:50', 'inoerp', '01-07-2013 02:29:50'),
(2, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 03:32:44', 'inoerp', '01-07-2013 03:32:44'),
(3, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 04:02:59', 'inoerp', '01-07-2013 04:02:59'),
(4, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, 'inoerp', '01-07-2013 09:47:42', 'inoerp', '01-07-2013 09:47:42');

-- --------------------------------------------------------

--
-- Table structure for table `module`
--

CREATE TABLE IF NOT EXISTS `module` (
  `module_id` int(12) NOT NULL auto_increment,
  `number` int(12) NOT NULL,
  `name` varchar(50) NOT NULL,
  `description` varchar(200) default NULL,
  `created_by` varchar(100) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(100) default NULL,
  `last_update_date` varchar(50) default NULL,
  PRIMARY KEY  (`module_id`),
  UNIQUE KEY `number` (`number`,`name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=14 ;

--
-- Dumping data for table `module`
--

INSERT INTO `module` (`module_id`, `number`, `name`, `description`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, 1, 'system', 'System', 'inoerp', '01-Jan-2013', 'inoerp', '01-Jan-2013'),
(2, 100, 'gl', 'General Ledger', NULL, NULL, 'inoerp', '18-06-13 01:54:41'),
(3, 101, 'ap', 'Accounts Payable', NULL, NULL, 'inoerp', '11-06-13 17:51:38'),
(4, 102, 'ar', 'Accounts Receviable', NULL, NULL, NULL, NULL),
(5, 103, 'fa', 'Fixed Asset', NULL, NULL, NULL, NULL),
(6, 200, 'inv', 'Inventory', NULL, NULL, NULL, NULL),
(7, 201, 'po', 'Purchasing', NULL, NULL, NULL, NULL),
(8, 202, 'om', 'Order Management', NULL, NULL, NULL, NULL),
(9, 203, 'bom', 'Bills of Material', NULL, NULL, NULL, NULL),
(10, 204, 'wip', 'Work in Process', NULL, NULL, NULL, NULL),
(11, 205, 'fp', 'Forecast & Planning', NULL, NULL, 'inoerp', '11-06-13 17:57:20'),
(12, 104, 'cm', 'Cash Management', 'inoerp', '11-06-2013 17:57:47', 'inoerp', '11-06-2013 17:57:47'),
(13, 2, 'org', 'Organization', 'inoerp', '12-06-2013 04:15:21', 'inoerp', '12-06-2013 04:15:21');

-- --------------------------------------------------------

--
-- Table structure for table `option_detail`
--

CREATE TABLE IF NOT EXISTS `option_detail` (
  `option_detail_id` int(12) unsigned NOT NULL auto_increment,
  `option_id_d` int(12) NOT NULL,
  `option_line_id_d` varchar(12) NOT NULL,
  `option_details_code` varchar(50) NOT NULL,
  `description_d` varchar(255) default NULL,
  `efid_d` int(12) default NULL,
  `status_d` varchar(50) default 'disabled',
  `rev_enabled_d` varchar(50) default 'disabled',
  `rev_number_d` int(10) default NULL,
  `effective_start_date_d` varchar(50) default NULL,
  `effective_end_date_d` varchar(50) default NULL,
  `created_by_d` varchar(40) NOT NULL default '',
  `creation_date_d` varchar(50) default NULL,
  `last_update_by_d` varchar(40) NOT NULL default '',
  `last_update_date_d` varchar(50) default NULL,
  PRIMARY KEY  (`option_detail_id`),
  KEY `option_id_d` (`option_id_d`),
  KEY `option_line_id_d` (`option_line_id_d`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `option_header`
--

CREATE TABLE IF NOT EXISTS `option_header` (
  `option_id` int(10) unsigned NOT NULL auto_increment,
  `access_level` varchar(20) NOT NULL default 'both',
  `option_type` varchar(50) NOT NULL,
  `description` varchar(200) default NULL,
  `module` varchar(50) NOT NULL default 'system',
  `efid` int(12) default NULL,
  `status` varchar(20) default NULL,
  `rev_enabled` varchar(20) default NULL,
  `rev_number` int(10) default NULL,
  `created_by` varchar(40) NOT NULL default '',
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(40) NOT NULL default '',
  `last_update_date` varchar(50) default NULL,
  PRIMARY KEY  (`option_id`),
  UNIQUE KEY `option_type` (`option_type`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=84 ;

--
-- Dumping data for table `option_header`
--

INSERT INTO `option_header` (`option_id`, `access_level`, `option_type`, `description`, `module`, `efid`, `status`, `rev_enabled`, `rev_number`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(83, 'system', 'COA_ACCOUNT_TYPE', 'Chart of account type - Asset A, Liability L, Owners Equity E, Expense E, Income I', '2', 1, 'enabled', 'enabled', 1, 'inoerp', '20-06-2013 17:21:21', 'inoerp', '20-06-2013 17:21:21'),
(82, 'both', 'COA01', 'Chart of account 01', '2', 1, 'enabled', 'enabled', 1, 'inoerp', '19-06-2013 08:50:06', 'inoerp', '19-06-2013 08:50:06'),
(81, 'system', 'TEST01', 'TEST01 Desc001', '1', 1, 'enabled', 'enabled', 1, 'inoerp', '18-06-2013 09:45:22', 'inoerp', '18-06-13 09:46:18'),
(80, 'system', 'COA_STRUCTURE', 'Chart of account structure', '13', 1, 'enabled', 'enabled', 0, 'inoerp', '16-06-2013 12:56:35', 'inoerp', '16-06-2013 12:56:35'),
(78, '', '', 'Demo Enterprise', '1', 0, '', '', 1, 'inoerp', '12-06-2013 10:40:00', 'inoerp', '18-06-13 08:30:09'),
(79, 'system', 'ADDRESS_TYPE', 'Address type', '13', 1, 'enabled', 'enabled', 1, 'inoerp', '15-06-2013 02:14:36', 'inoerp', '15-06-2013 02:14:36'),
(77, 'system', 'ORG_TYPE', 'Org Type', '1', 0, 'enabled', 'enabled', 1, 'inoerp', '10-06-2013 10:16:31', 'inoerp', '10-06-2013 10:16:31');

-- --------------------------------------------------------

--
-- Table structure for table `option_line`
--

CREATE TABLE IF NOT EXISTS `option_line` (
  `option_line_id` int(10) unsigned NOT NULL auto_increment,
  `option_id_l` int(12) NOT NULL,
  `option_line_code` varchar(50) NOT NULL,
  `value_l` varchar(50) NOT NULL,
  `description_l` varchar(255) default NULL,
  `efid_l` int(12) default NULL,
  `status_l` varchar(50) default 'disabled',
  `rev_enabled_l` varchar(50) default 'disabled',
  `rev_number_l` int(10) default NULL,
  `effective_start_date` varchar(50) default NULL,
  `effective_end_date` varchar(50) default NULL,
  `created_by_l` varchar(40) NOT NULL default '',
  `creation_date_l` varchar(50) default NULL,
  `last_update_by_l` varchar(40) NOT NULL default '',
  `last_update_date_l` varchar(50) default NULL,
  PRIMARY KEY  (`option_line_id`),
  UNIQUE KEY `option_code` (`option_line_code`),
  KEY `option_id` (`option_id_l`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=99 ;

--
-- Dumping data for table `option_line`
--

INSERT INTO `option_line` (`option_line_id`, `option_id_l`, `option_line_code`, `value_l`, `description_l`, `efid_l`, `status_l`, `rev_enabled_l`, `rev_number_l`, `effective_start_date`, `effective_end_date`, `created_by_l`, `creation_date_l`, `last_update_by_l`, `last_update_date_l`) VALUES
(22, 42, '', 'test200', 'test200', 0, '0', '0', 0, '2', '', 'inoerp', '04-06-2013 14:00:22', 'inoerp', '04-06-2013 14:00:22'),
(23, 45, 'TEST220A', 'TEST220A', 'TEST220A', 1, '1', '1', 1, '33', '33', 'inoerp', '04-06-2013 14:15:02', 'inoerp', '04-06-2013 14:15:02'),
(24, 45, 'TEST221', 'TEST221', 'TEST221', 0, '0', '0', 0, '0', '', 'inoerp', '04-06-2013 14:15:02', 'inoerp', '04-06-2013 14:15:02'),
(25, 49, 'TEST10', 'TEST10', 'TEST10', 0, '0', '0', 0, '', '', 'inoerp', '05-06-2013 06:12:29', 'inoerp', '05-06-2013 06:12:29'),
(26, 49, 'TEST11', 'TEST11', 'TEST11', 0, '0', '0', 0, '', '', 'inoerp', '05-06-2013 06:12:29', 'inoerp', '05-06-2013 06:12:29'),
(27, 56, 'TEST26', 'TEST26', 'TEST26', 0, '0', '0', 0, '', '', 'nishitdas', '05-06-2013 16:46:51', 'nishitdas', '05-06-2013 16:46:51'),
(65, 75, 'TEST1000A', 'TEST1000A value', 'TEST1000A description', 0, 'enabled', 'enabled', 0, '2', '2', 'inoerp', '09-06-2013 03:23:55', 'inoerp', '09-06-2013 03:23:55'),
(29, 43, 'TEST27A', 'TEST27', 'TEST27', 0, '0', '0', 0, '', '', 'nishitdas', '05-06-2013 16:53:48', 'nishitdas', '05-06-2013 16:53:48'),
(30, 58, 'TEST27c', 'TEST27', 'TEST27', 0, '0', '0', 0, '', '', 'nishitdas', '05-06-2013 16:55:52', 'nishitdas', '05-06-2013 16:55:52'),
(32, 55, 'TEST55B', 'value of TEST55B', 'Desc of TEST55B', 0, '0', '0', 0, '', '', 'inoerp', '07-06-2013 06:27:41', 'inoerp', '08-06-13 14:42:01'),
(33, 55, 'TEST55C', 'Value of TEST55C', 'Desc of TEST55C', 0, '0', '0', 0, '', '', 'inoerp', '07-06-2013 06:27:41', 'inoerp', '08-06-13 14:42:01'),
(70, 76, 'TEST500A', 'val', 'desc of 70', 1, 'enabled', 'enabled', 0, '2013-06-01', '2015-07-16', 'inoerp', '09-06-2013 05:46:46', 'inoerp', '09-06-13 06:11:48'),
(35, 60, 'TEST100A', 'TEST100A', 'TEST100A', 0, '0', '0', 0, '', '', 'inoerp', '07-06-2013 10:12:02', 'inoerp', '07-06-2013 10:12:02'),
(36, 60, 'TEST100B', 'TEST100B', 'TEST100B', 0, '0', '0', 0, '', '', 'inoerp', '07-06-2013 10:12:02', 'inoerp', '07-06-2013 10:12:02'),
(37, 60, 'TEST100C', 'TEST100C', 'TEST100C', 0, '0', '0', 0, '', '', 'inoerp', '07-06-2013 10:12:53', 'inoerp', '07-06-2013 10:12:53'),
(38, 50, 'TESTSTS', 'TSTSTS', 'TTSSTS', 1, '1', '0', NULL, NULL, NULL, '', NULL, '', NULL),
(39, 0, 'TEST101A', 'TEST101A', 'TEST101A', 0, '0', '0', 0, '', '', 'inoerp', '07-06-2013 13:33:16', 'inoerp', '07-06-2013 13:33:16'),
(40, 0, 'TEST101B', 'TEST101B', 'TEST101B', 0, '0', '0', 0, '', '', 'inoerp', '07-06-2013 13:33:16', 'inoerp', '07-06-2013 13:33:16'),
(41, 65, 'TEST223A', 'TEST223A Value', 'TEST223A Desc', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 11:54:02', 'inoerp', '08-06-2013 11:54:02'),
(42, 66, 'TEST225A', 'TEST225A', 'TEST225A', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 12:10:31', 'inoerp', '08-06-2013 12:10:31'),
(43, 67, 'TEST230B', 'TEST230B', 'TEST230B', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 12:23:34', 'inoerp', '08-06-13 16:57:10'),
(44, 69, 'TEST250Bxx', 'TEST250A', 'TEST250A', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 12:43:48', 'inoerp', '08-06-13 18:46:44'),
(45, 63, 'TEST221a', 'TEST221a', 'TEST221a desc', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 13:10:33', 'inoerp', '08-06-13 13:10:48'),
(46, 62, 'TEST120A', 'TEST12A', 'TEST12A', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 13:49:18', 'inoerp', '08-06-2013 13:49:18'),
(69, 76, 'TEST500', 'TEST500 val', 'TEST500desc', 1, 'enabled', 'enabled', 0, '2013-06-01', '2013-06-28', 'inoerp', '09-06-2013 05:42:54', 'inoerp', '09-06-13 06:11:48'),
(49, 67, 'TEST230C', 'TEST230C value', 'TEST230C desc', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 16:57:10', 'inoerp', '08-06-2013 16:57:10'),
(50, 71, 'CODE01', 'VALUE01', 'DESC01 code01', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 17:38:26', 'inoerp', '08-06-13 17:50:44'),
(51, 71, 'CODE03', 'VALUE02 of CODE02', 'DESC01 of code01', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 17:38:45', 'inoerp', '08-06-13 17:50:44'),
(52, 72, 'TEST400A', 'value', 'TEST400A desc', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 17:45:06', 'inoerp', '08-06-13 17:45:49'),
(53, 72, 'TEST400B', 'TEST400Bvalue', 'desc', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 17:45:06', 'inoerp', '08-06-13 17:45:27'),
(66, 75, 'TEST1000B', 'TEST1000A value', 'TEST1000A description', 0, 'enabled', 'enabled', 0, '0', '0', 'inoerp', '09-06-2013 03:30:16', 'inoerp', '09-06-2013 03:30:16'),
(59, 69, 'TEST250B', 'TEST250A', 'TEST250A', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 18:43:55', 'inoerp', '08-06-2013 18:43:55'),
(60, 73, 'TEST26E', 'TEST260D val', 'TEST260A desc', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 20:24:07', 'inoerp', '08-06-2013 20:24:07'),
(58, 73, 'TEST26D', 'TEST260D val', 'TEST260A desc', 0, '0', '0', 0, '', '', 'inoerp', '08-06-2013 18:12:25', 'inoerp', '08-06-13 18:53:50'),
(64, 46, 'TEST1111', 'TEST1111', 'TEST1111', 0, 'enabled', 'enabled', 0, '', '', 'inoerp', '09-06-2013 03:17:56', 'inoerp', '09-06-2013 03:17:56'),
(67, 46, 'TEST1', 'TEST1', 'TEST1', 0, 'enabled', 'enabled', 0, '%01-%01-%1970', '0', 'inoerp', '09-06-2013 03:46:46', 'inoerp', '09-06-2013 03:46:46'),
(68, 46, 'TEST2', 'TEST1111', 'TEST1111', 0, 'enabled', 'enabled', 0, '01-01-1970', '1', 'inoerp', '09-06-2013 03:49:24', 'inoerp', '09-06-2013 03:49:24'),
(71, 77, 'ENTERPRISE', 'ENTERPRISE', 'Enterprise Org', 0, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '10-06-2013 10:23:48', 'inoerp', '10-06-2013 10:23:48'),
(72, 77, 'LEGAL_ORG', 'LEGAL_ORG', 'Legal Org', 0, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '10-06-2013 10:23:48', 'inoerp', '10-06-2013 10:23:48'),
(73, 77, 'BUSINESS_ORG', 'BUSINESS_ORG', 'Business Org', 0, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '10-06-2013 10:23:48', 'inoerp', '10-06-2013 10:23:48'),
(74, 77, 'INVENTORY_ORG', 'INVENTORY_ORG', 'Inventory Org', 0, '', '', 1, '2000-01-01', '', 'inoerp', '10-06-2013 10:23:48', 'inoerp', '10-06-2013 10:23:48'),
(75, 79, 'INTERNATIONAL', 'INTERNATIONAL', 'Standard International Format', 1, 'enabled', 'enabled', 1, '2000-01-01', '2000-01-01', 'inoerp', '15-06-2013 02:17:38', 'inoerp', '15-06-2013 02:17:38'),
(76, 79, 'US_STYLE', 'US_STYLE', 'US Format', 1, 'enabled', 'enabled', 1, '2000-01-01', '2000-01-01', 'inoerp', '15-06-2013 02:17:38', 'inoerp', '15-06-2013 02:17:38'),
(77, 80, 'SEGMENT1', 'Legal Org', 'Legal Organization', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(78, 80, 'SEGMENT2', 'Business Org', 'Business Organization', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(79, 80, 'SEGMENT3', 'Cost Center', 'Cost center', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(80, 80, 'SEGMENT4', 'Account', 'Natural account', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(81, 80, 'SEGMENT5', 'Product', 'Product', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(82, 80, 'SEGMENT6', 'Project', 'Project', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(83, 80, 'SEGMENT7', 'InterCompany', 'Inter-Company Segment', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(84, 80, 'SEGMENT8', 'TBU', 'Feature Use', 1, 'enabled', 'enabled', 1, '2000-01-01', '', 'inoerp', '16-06-2013 13:05:23', 'inoerp', '16-06-2013 13:05:23'),
(85, 81, 'TEST01Val01', 'TEST01Val01', 'TEST01Val01 Desc', 1, 'enabled', 'enabled', 0, '', '', 'inoerp', '18-06-2013 09:46:00', 'inoerp', '18-06-13 09:46:26'),
(86, 81, 'TEST01Val003111', 'TEST01Val02', 'TEST01Val02Desc', 1, 'enabled', '', 0, '', '', 'inoerp', '18-06-2013 09:46:00', 'inoerp', '18-06-13 09:46:26'),
(87, 82, 'LEGAL_UNIT', 'Legal Unit', 'Represents Legal Unit', 1, 'enabled', 'enabled', 0, '2000-01-01', '', 'inoerp', '19-06-2013 08:53:17', 'inoerp', '19-06-13 08:55:41'),
(88, 82, 'BUSINESS_UNIT', 'Business Unit', 'Represents Business Unit', 1, 'enabled', 'enabled', 0, '2000-01-01', '', 'inoerp', '19-06-2013 08:53:17', 'inoerp', '19-06-13 08:55:41'),
(89, 82, 'COST_CENTER', 'Cost center', 'Represents Cost Center', 1, 'enabled', 'enabled', 0, '2000-01-01', '', 'inoerp', '19-06-2013 08:53:17', 'inoerp', '19-06-13 08:55:41'),
(90, 82, 'PRODUCT_CODE', 'product code', 'Represents Product code', 1, 'enabled', 'enabled', 0, '2000-01-01', '', 'inoerp', '19-06-2013 08:53:17', 'inoerp', '19-06-13 08:55:41'),
(91, 82, 'INTERCOMPANY', 'Intercompany', 'Intercompany', 1, 'enabled', 'enabled', 0, '2000-01-01', '', 'inoerp', '19-06-2013 08:53:17', 'inoerp', '19-06-13 08:55:41'),
(92, 82, 'ACCOUNT', 'Natural account', 'Represents NA', 1, 'enabled', 'enabled', 0, '2000-01-01', '', 'inoerp', '19-06-2013 08:55:41', 'inoerp', '19-06-2013 08:55:41'),
(93, 83, 'A', 'Asset', 'Asset', 0, 'enabled', 'enabled', 0, '1950-01-01', '', 'inoerp', '20-06-2013 17:24:41', 'inoerp', '20-06-2013 17:24:41'),
(94, 83, 'L', 'Liability', 'Liability', 0, 'enabled', 'enabled', 0, '1950-01-01', '', 'inoerp', '20-06-2013 17:24:41', 'inoerp', '20-06-2013 17:24:41'),
(95, 83, 'E', 'Equity', 'Owners Equity', 0, 'enabled', 'enabled', 0, '1950-01-01', '', 'inoerp', '20-06-2013 17:24:41', 'inoerp', '20-06-2013 17:24:41'),
(96, 83, 'X', 'Expense', 'Expense', 0, 'enabled', 'enabled', 0, '1950-01-01', '', 'inoerp', '20-06-2013 17:24:41', 'inoerp', '20-06-2013 17:24:41'),
(97, 83, 'I', 'Income', 'Income', 0, 'enabled', 'enabled', 0, '1950-01-01', '', 'inoerp', '20-06-2013 17:24:41', 'inoerp', '20-06-2013 17:24:41'),
(98, 83, 'C', 'Contra', 'Contra', 0, 'enabled', 'enabled', 0, '1950-01-01', '', 'inoerp', '20-06-2013 17:24:41', 'inoerp', '20-06-2013 17:24:41');

-- --------------------------------------------------------

--
-- Table structure for table `org`
--

CREATE TABLE IF NOT EXISTS `org` (
  `org_id` int(12) NOT NULL auto_increment,
  `name` varchar(50) NOT NULL,
  `type` varchar(50) NOT NULL,
  `description` varchar(200) default NULL,
  `enterprise_id` int(12) NOT NULL default '1',
  `legal_id` int(12) default NULL,
  `business_id` int(12) default NULL,
  `inventory_id` int(12) default NULL,
  `ef_id` int(12) default NULL,
  `status` varchar(50) default NULL,
  `rev_enabled` varchar(50) default NULL,
  `rev_number` int(12) default NULL,
  `address_id` int(12) default NULL,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) NOT NULL,
  `last_update_date` varchar(50) NOT NULL,
  PRIMARY KEY  (`org_id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=35 ;

--
-- Dumping data for table `org`
--

INSERT INTO `org` (`org_id`, `name`, `type`, `description`, `enterprise_id`, `legal_id`, `business_id`, `inventory_id`, `ef_id`, `status`, `rev_enabled`, `rev_number`, `address_id`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(1, 'TEST25', 'ENTERPRISE', 'TEST25A', 0, 0, 0, 0, 0, NULL, '', 0, NULL, 'inoerp', '12-06-2013 15:37:39', 'inoerp', '12-06-2013 15:37:39'),
(2, 'TEST51', 'ENTERPRISE', 'TEST51', 0, 0, 0, 0, 1, NULL, '', 1, NULL, 'inoerp', '13-06-2013 02:52:45', 'inoerp', '13-06-2013 02:52:45'),
(3, 'TEST52', 'ENTERPRISE', 'TEST52', 0, 0, 0, 0, 0, NULL, '', 1, NULL, 'inoerp', '13-06-2013 03:17:13', 'inoerp', '13-06-2013 03:17:13'),
(4, 'TEST53', 'ENTERPRISE', 'TEST53', 0, 0, 0, 0, 1, NULL, '', 1, NULL, 'inoerp', '13-06-2013 03:18:18', 'inoerp', '13-06-2013 03:18:18'),
(5, 'TEST54', 'ENTERPRISE', 'TEST54', 0, 0, 0, 0, 1, NULL, '', 1, NULL, 'inoerp', '13-06-2013 05:14:02', 'inoerp', '13-06-2013 05:14:02'),
(6, 'test55', 'ENTERPRISE', 'test55', 0, 0, 0, 0, 0, NULL, '', 1, NULL, 'inoerp', '13-06-2013 05:16:42', 'inoerp', '13-06-2013 05:16:42'),
(7, 'TEST56', 'ENTERPRISE', 'TEST56', 0, 0, 0, 0, 0, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 05:26:54', 'inoerp', '13-06-2013 05:26:54'),
(8, 'TEST60', 'ENTERPRISE', 'TEST60', 0, 0, 0, 0, 0, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 07:05:23', 'inoerp', '13-06-2013 07:05:23'),
(9, 'TEST61', 'ENTERPRISE', 'TEST61', 0, 0, 0, 0, 0, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 07:10:05', 'inoerp', '13-06-2013 07:10:05'),
(10, 'TEST62', 'ENTERPRISE', 'TEST62', 0, 0, 0, 0, 1, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 07:10:54', 'inoerp', '13-06-2013 07:10:54'),
(11, 'TEST65', 'ENTERPRISE', 'TEST65', 0, 0, 0, 0, 0, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 07:12:14', 'inoerp', '13-06-2013 07:12:14'),
(12, 'TEST66', 'ENTERPRISE', 'TEST66', 0, 0, 0, 0, 1, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 07:23:07', 'inoerp', '13-06-2013 07:23:07'),
(13, 'test70', 'ENTERPRISE', 'test70', 0, 0, 0, 0, 1, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 09:12:58', 'inoerp', '13-06-2013 09:12:58'),
(14, 'TEST80', 'ENTERPRISE', 'TEST80', 0, 0, 0, 0, 0, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 09:19:17', 'inoerp', '13-06-2013 09:19:17'),
(15, 'TEST81A', 'ENTERPRISE', 'TEST81', 0, 0, 0, 0, 1, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 09:21:06', 'inoerp', '13-06-13 10:51:10'),
(16, 'TEST85', 'ENTERPRISE', 'TEST85', 24, 0, 0, 0, 1, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 09:27:47', 'inoerp', '13-06-2013 09:27:47'),
(17, 'TEST90A', 'ENTERPRISE', 'TEST90B', 25, 0, 0, 0, 2, NULL, 'disabled', 2, NULL, 'inoerp', '13-06-2013 10:38:19', 'inoerp', '13-06-13 10:54:29'),
(18, 'TEST100', 'ENTERPRISE', 'TEST100', 26, 0, 0, 0, 0, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 13:49:00', 'inoerp', '13-06-2013 13:49:00'),
(19, 'TEST101', 'ENTERPRISE', 'TEST101', 27, 0, 0, 0, 0, NULL, 'enabled', 1, NULL, 'inoerp', '13-06-2013 13:52:45', 'inoerp', '13-06-2013 13:52:45'),
(20, 'test102AB', 'ENTERPRISE', 'test102A', 28, 0, 0, 0, 0, 'enabled', 'enabled', 2, NULL, 'inoerp', '13-06-2013 13:57:11', 'inoerp', '14-06-13 02:55:50'),
(21, 'TEST500a', 'ENTERPRISE', 'zxczzxcxzcz', 29, 0, 0, 0, 1, 'enabled', 'enabled', 1, NULL, 'inoerp', '14-06-2013 11:36:47', 'inoerp', '14-06-13 15:00:00'),
(22, 'TEST502ASA', 'ENTERPRISE', 'TEST502A', 31, 0, 0, 0, 1, 'enabled', 'enabled', 1, 83, 'inoerp', '14-06-2013 15:00:51', 'inoerp', '16-06-13 07:08:12'),
(23, 'tesr555', 'ENTERPRISE', 'fftyuu', 32, 0, 0, 0, 2, 'enabled', 'enabled', 1, 83, 'inoerp', '15-06-2013 08:12:44', 'inoerp', '16-06-13 06:14:58'),
(24, 'ino Enterprise', 'ENTERPRISE', 'ino Enterprise', 33, 0, 0, 0, 1, 'enabled', 'enabled', 1, 83, 'inoerp', '16-06-2013 06:31:44', 'inoerp', '29-06-13 08:45:16'),
(25, 'TEST104', 'ENTERPRISE', 'TEST 104', 34, 0, 0, 0, 0, NULL, 'enabled', 0, 81, 'inoerp', '01-07-2013 01:18:57', 'inoerp', '01-07-2013 01:18:57'),
(26, 'ino_corp_legalOrg', 'LEGAL_ORG', 'ino_corp_coa1', 24, 1, 0, 0, 1, 'enabled', 'enabled', 0, 81, 'inoerp', '01-07-2013 02:29:50', 'inoerp', '01-07-13 02:32:25'),
(27, 'ENT_01', 'ENTERPRISE', 'ENT_01', 35, 0, 0, 0, 1, NULL, 'enabled', 0, 0, 'inoerp', '01-07-2013 03:17:53', 'inoerp', '01-07-2013 03:17:53'),
(28, 'LO_TEST01', 'LEGAL_ORG', 'Desc of LO TEST01', 2, 2, 0, 0, 1, 'enabled', 'enabled', 0, 79, 'inoerp', '01-07-2013 03:32:44', 'inoerp', '01-07-13 10:18:20'),
(29, 'LO_01', 'LEGAL_ORG', 'Legal Org for Ino Enterprise', 24, 3, 0, 0, 1, NULL, 'enabled', 1, 81, 'inoerp', '01-07-2013 04:02:59', 'inoerp', '01-07-2013 04:02:59'),
(30, 'LO_002', 'LEGAL_ORG', 'Desc of LO002', 1, 4, 0, 0, 1, NULL, 'enabled', 0, 0, 'inoerp', '01-07-2013 09:47:42', 'inoerp', '01-07-2013 09:47:42'),
(31, 'BO_001', 'BUSINESS_ORG', 'Desc of BO_01', 24, 26, 4, 0, 0, NULL, 'enabled', 1, 0, 'inoerp', '01-07-2013 09:53:44', 'inoerp', '01-07-2013 09:53:44'),
(32, 'Ino corp Business Org', 'BUSINESS_ORG', 'Primary business org of Ino Corp', 24, 26, 5, 0, 1, '', 'enabled', 1, 81, 'inoerp', '01-07-2013 09:57:32', 'inoerp', '01-07-13 10:06:40'),
(33, 'BO_004', 'BUSINESS_ORG', 'BO_004', 24, 26, 7, 0, 0, NULL, '', 0, 0, 'inoerp', '01-07-2013 11:44:23', 'inoerp', '01-07-2013 11:44:23'),
(34, 'IO_001', 'INVENTORY_ORG', 'TEST IO', 24, 26, 31, 1, 0, 'enabled', 'enabled', 1, 0, 'inoerp', '01-07-2013 12:53:19', 'inoerp', '01-07-13 12:53:38');

-- --------------------------------------------------------

--
-- Table structure for table `path`
--

CREATE TABLE IF NOT EXISTS `path` (
  `path_id` int(12) NOT NULL auto_increment,
  `parent_id` int(12) NOT NULL,
  `name` varchar(256) NOT NULL default 'none',
  `value` varchar(512) NOT NULL default 'none',
  `description` varchar(512) default NULL,
  `module` varchar(60) NOT NULL default 'system',
  `primary` int(2) NOT NULL default '0',
  `created_by` varchar(100) default NULL,
  `creation_date` date default NULL,
  `last_updated_by` varchar(100) default NULL,
  `last_updation_date` date default NULL,
  `TBU` varchar(100) default NULL,
  PRIMARY KEY  (`path_id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=42 ;

--
-- Dumping data for table `path`
--

INSERT INTO `path` (`path_id`, `parent_id`, `name`, `value`, `description`, `module`, `primary`, `created_by`, `creation_date`, `last_updated_by`, `last_updation_date`, `TBU`) VALUES
(1, 0, 'home', 'index.php', 'Home Page', '1', 1, 'inoerp', '2013-05-26', 'inoerp', '2014-06-13', NULL),
(27, 23, 'Address', 'modules/org/address/address.php', 'Address create , update & delete', '13', 0, 'inoerp', '2015-06-13', 'inoerp', '2015-06-13', NULL),
(6, 0, 'Supplier', 'modules/ap/suppliers/supplier.php', 'Supplier List', '3', 1, 'inoerp', '2026-05-13', 'inoerp', '2014-06-13', NULL),
(14, 13, 'Registraion', 'extensions/user/user_registration.php', 'New user registration', '1', 0, 'inoerp', '2027-05-13', 'inoerp', '2014-06-13', NULL),
(7, 6, 'Supplier Entry', 'modules/ap/suppliers/supplier_entry.php', 'Supplier Entry', '3', 0, 'inoerp', '2026-05-13', 'inoerp', '2014-06-13', NULL),
(11, 26, 'Paths', 'extensions/path/paths.php', 'All paths', '1', 0, 'inoerp', '2027-05-13', 'inoerp', '2014-06-13', NULL),
(13, 0, 'Users', 'extensions/user/users.php', 'All users', '1', 1, 'inoerp', '2027-05-13', 'inoerp', '2014-06-13', NULL),
(19, 1, 'Install', 'engine/module/module.php', 'Module', '1', 0, 'inoerp', '2030-05-13', 'inoerp', '2014-06-13', NULL),
(17, 6, 'Site entry', 'modules/ap/suppliers/supplier_site_entry.php', 'Supplier site entry', '3', 0, 'inoerp', '2029-05-13', 'inoerp', '2014-06-13', NULL),
(18, 0, 'Option', 'modules/system/option/option.php', 'Options', '1', 1, 'inoerp', '2030-05-13', 'inoerp', '2014-06-13', NULL),
(20, 18, 'Option view', 'modules/system/option/option_view.php', 'View all the options', '1', 0, 'inoerp', '2031-05-13', 'inoerp', '2014-06-13', NULL),
(21, 1, 'Modules', 'modules/system/module/modules.php', 'All modules', '1', 0, 'inoerp', '2009-06-13', 'inoerp', '2014-06-13', NULL),
(22, 1, 'Module', 'modules/system/module/module.php', 'Module creation & update', '1', 0, 'inoerp', '2009-06-13', 'inoerp', '2014-06-13', NULL),
(23, 0, 'Org', 'modules/org/org.php', 'Organizations', '13', 1, 'inoerp', '2012-06-13', 'inoerp', '2014-06-13', NULL),
(24, 23, 'Enterprise', 'modules/org/enterprise/enterprise.php', 'Enterprise', '13', 0, 'inoerp', '2012-06-13', 'inoerp', '2014-06-13', NULL),
(41, 23, 'Inventory Org', 'modules/org/inventory_org/inventory_org.php', 'Inventory Organization', '13', 0, 'inoerp', '2001-07-13', 'inoerp', '2001-07-13', NULL),
(26, 0, 'Path', 'extensions/path/path.php', 'Path - creation, update & Delete', '1', 1, 'inoerp', '2014-06-13', 'inoerp', '2014-06-13', NULL),
(28, 23, 'Addresses', 'modules/org/address/addresses.php', 'All the addresses', '13', 0, 'inoerp', '2015-06-13', 'inoerp', '2015-06-13', NULL),
(30, 0, 'COA', 'modules/gl/coa/coa.php', 'Char of Account', '2', 1, 'inoerp', '2018-06-13', 'inoerp', '2021-06-13', NULL),
(31, 30, 'COA Segment Values', 'modules/gl/coa/coa_segment_values.php', 'Chart of account segment values', '2', 0, 'inoerp', '2021-06-13', 'inoerp', '2021-06-13', NULL),
(36, 30, 'All COA', 'modules/gl/coa/coas.php', 'All chart of accounts', '2', 0, 'inoerp', '2026-06-13', 'inoerp', '2026-06-13', NULL),
(37, 30, 'Account Combinations', 'modules/gl/coa_combination/coa_combination.php', 'Char of account combinations', '2', 0, 'inoerp', '2027-06-13', 'inoerp', '2027-06-13', NULL),
(38, 23, 'Legal Org', 'modules/org/legal_org/legal_org.php', 'Legal Organization', '13', 0, 'inoerp', '2029-06-13', 'inoerp', '2029-06-13', NULL),
(39, 23, 'Legal Orgs', 'modules/org/legal_org/legal_orgs.php', 'List of all Legal Orgs', '13', 0, 'inoerp', '2001-07-13', 'inoerp', '2001-07-13', NULL),
(40, 23, 'Business Org', 'modules/org/business_org/business_org.php', 'Business Organization', '13', 0, 'inoerp', '2001-07-13', 'inoerp', '2001-07-13', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `supplier`
--

CREATE TABLE IF NOT EXISTS `supplier` (
  `supplier_id` int(11) NOT NULL auto_increment,
  `supplier_number` int(11) NOT NULL,
  `supplier_name` varchar(60) NOT NULL,
  `tax_country` varchar(40) default NULL,
  `tax_reg_no` varchar(40) default NULL,
  `tax_payer_id` varchar(40) default NULL,
  `supplier_address_id` int(12) NOT NULL default '1',
  `supplier_contact_id` int(12) NOT NULL default '1',
  `created_by` varchar(60) NOT NULL default 'admin',
  `creation_date` datetime NOT NULL default '0000-00-00 00:00:00',
  `last_updated_by` varchar(60) NOT NULL default 'admin',
  `last_updation_date` datetime NOT NULL default '0000-00-00 00:00:00',
  `revision_enabled` char(10) NOT NULL default 'y',
  `revision_number` int(11) NOT NULL default '1',
  PRIMARY KEY  (`supplier_id`),
  UNIQUE KEY `supplier_number` (`supplier_number`),
  UNIQUE KEY `supplier_name` (`supplier_name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=27 ;

--
-- Dumping data for table `supplier`
--

INSERT INTO `supplier` (`supplier_id`, `supplier_number`, `supplier_name`, `tax_country`, `tax_reg_no`, `tax_payer_id`, `supplier_address_id`, `supplier_contact_id`, `created_by`, `creation_date`, `last_updated_by`, `last_updation_date`, `revision_enabled`, `revision_number`) VALUES
(1, 1000, 'ABCD copr', NULL, NULL, NULL, 0, 0, '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(2, 1001, '        Inoideas Techonology', NULL, NULL, NULL, 0, 0, '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(4, 1003, 'Ford Motors', NULL, NULL, NULL, 0, 0, '', '2013-05-11 00:00:00', 'erew', '2013-05-11 00:00:00', 'y', 0),
(5, 1005, '                Genesis tech01', NULL, NULL, NULL, 0, 0, '', '2015-05-11 00:00:00', 'erew', '2015-05-11 00:00:00', 'y', 0),
(6, 1006, 'Raven Infosys Ltd', NULL, NULL, NULL, 0, 0, '', '2016-06-11 00:00:00', 'erew', '2016-06-11 00:00:00', 'y', 0),
(7, 1007, 'S & HHealth care', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(8, 10012, 'Vodafone', NULL, NULL, NULL, 0, 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', '', 0),
(9, 1013, 'Indian Post Office', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(10, 10019, 'BCCI Inc', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(11, 100032, 'WIPRO Inc', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(12, 10023, '                    IBM what?', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(13, 10024, 'Accentrure', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(14, 10030, 'Tata Motors', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(16, 10032, '    Microsoft', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(18, 2312, 'qwqwe', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(19, 13221, 'ssdgs', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(20, 325325, '        WIPRO', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(21, 10101, 'KPIT', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(22, 1223, 'Cummins', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(23, 1299129, 'KPITCummins', NULL, NULL, NULL, 0, 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(24, 21424, 'KPMG', NULL, NULL, NULL, 1, 1, 'admin', '0000-00-00 00:00:00', 'admin', '0000-00-00 00:00:00', 'y', 0),
(25, 122, 'IGate', NULL, NULL, NULL, 1, 1, 'admin', '0000-00-00 00:00:00', 'admin', '0000-00-00 00:00:00', 'y', 0),
(26, 111, 'Inoideas', NULL, NULL, NULL, 1, 1, 'admin', '0000-00-00 00:00:00', 'admin', '0000-00-00 00:00:00', 'y', 1);

-- --------------------------------------------------------

--
-- Table structure for table `supplier1`
--

CREATE TABLE IF NOT EXISTS `supplier1` (
  `supplier_id` int(11) NOT NULL auto_increment,
  `supplier_number` int(11) NOT NULL,
  `address_id` int(11) NOT NULL,
  `contact_id` int(11) NOT NULL,
  `bank_account_id` int(11) NOT NULL,
  `supp_type` varchar(60) NOT NULL default '',
  `supp_name` varchar(60) NOT NULL default '',
  `supp_ref` varchar(30) NOT NULL default '',
  `address` tinytext NOT NULL,
  `supp_address` tinytext NOT NULL,
  `gst_no` varchar(25) NOT NULL default '',
  `contact` varchar(60) NOT NULL default '',
  `supp_account_no` varchar(40) NOT NULL default '',
  `website` varchar(100) NOT NULL default '',
  `bank_account` varchar(60) NOT NULL default '',
  `curr_code` char(3) default NULL,
  `payment_terms` varchar(11) default NULL,
  `tax_included` tinyint(1) NOT NULL default '0',
  `dimension_id` int(11) default '0',
  `dimension2_id` int(11) default '0',
  `tax_group_id` int(11) NOT NULL,
  `credit_limit` double NOT NULL default '0',
  `purchase_account` varchar(15) NOT NULL default '',
  `payable_account` varchar(15) NOT NULL default '',
  `payment_discount_account` varchar(15) NOT NULL default '',
  `pre_payment_account` varchar(15) NOT NULL default '',
  `notes` tinytext NOT NULL,
  `inactive` tinyint(1) NOT NULL default '0',
  `created_by` varchar(60) NOT NULL default '',
  `creation_date` datetime NOT NULL,
  `last_updated_by` varchar(60) NOT NULL default '',
  `last_updation_date` datetime NOT NULL,
  `revision_enabled` char(1) NOT NULL default '',
  `revision_number` int(11) NOT NULL,
  PRIMARY KEY  (`supplier_id`),
  UNIQUE KEY `supplier_number` (`supplier_number`),
  KEY `supp_ref` (`supp_ref`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=24 ;

--
-- Dumping data for table `supplier1`
--

INSERT INTO `supplier1` (`supplier_id`, `supplier_number`, `address_id`, `contact_id`, `bank_account_id`, `supp_type`, `supp_name`, `supp_ref`, `address`, `supp_address`, `gst_no`, `contact`, `supp_account_no`, `website`, `bank_account`, `curr_code`, `payment_terms`, `tax_included`, `dimension_id`, `dimension2_id`, `tax_group_id`, `credit_limit`, `purchase_account`, `payable_account`, `payment_discount_account`, `pre_payment_account`, `notes`, `inactive`, `created_by`, `creation_date`, `last_updated_by`, `last_updation_date`, `revision_enabled`, `revision_number`) VALUES
(1, 1000, 1, 1, 1, 'External', 'ABCD copr', 'REF001', 'B-102, Hutson Road,\r\nLos Angeles, CA\r\nUS -100001', '            Enter the complete supplier address', '', '', '', '', '', 'USD', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(2, 1001, 1, 1, 1, 'Employee', '        Inoideas Techonology', 'REF002', 'India', '            Enter the complete supplier address', '', '', '', '', '', 'USD', '1', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(3, 1002, 1, 1, 1, 'External', 'IRS US', 'REF003', 'A-108, Disel Road\r\nSingapore - 412121', '            Enter the complete supplier address', '', '', '', 'www.rtes.com', '', 'USD', '3', 0, 0, 0, 0, 0, '', '', '', '', '', 0, '', '2013-05-11 00:00:00', 'test', '2013-05-11 00:00:00', 'N', 0),
(4, 1003, 2, 2, 2, 'External', 'Ford Motors', 'REF004', 'PO BOX 213\r\nSadninare\r\nSweden -131313', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2013-05-11 00:00:00', 'erew', '2013-05-11 00:00:00', 'y', 0),
(5, 1005, 2, 2, 2, 'External', '                Genesis tech01', 'REF004', 'PO BOX 215\nSadninare Sweden -151515', '            Enter the complete supplier address', '', '', '', '', '', 'EUR', '3', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2015-05-11 00:00:00', 'erew', '2015-05-11 00:00:00', 'y', 0),
(6, 1006, 2, 2, 2, 'External', 'Raven Infosys Ltd', 'REF004', 'PO BOX 216\nSadninare Sweden -161616', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2016-06-11 00:00:00', 'erew', '2016-06-11 00:00:00', 'y', 0),
(7, 1007, 2, 2, 2, 'External', 'S & HHealth care', 'REF004', 'PO BOX 217 Sadninare Sweden -171717', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(8, 10012, 0, 0, 0, '', 'Vodafone', '', 'Vodafone Office\r\nMumbai\r\nIndia', '', '', '', '', '', '', 'INR', '30', 0, 0, 0, 0, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', '', 0),
(9, 1013, 2, 2, 2, 'External', 'Indian Post Office', 'REF004', 'PO BOX 217 Sakinaa Delhi India -171717', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(10, 10019, 2, 2, 2, 'Internal', 'BCCI Inc', 'REF004', 'BCCI\r\nNew Delhi\r\nIndia', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(11, 100032, 2, 2, 2, 'Internal', 'WIPRO Inc', 'REF004', 'WIpro\r\nBanglore India', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(12, 10023, 2, 2, 2, 'External', '                    IBM what?', 'REF004', 'IBM Corp.\r\nCA\r\nUSA', '            Enter the complete supplier address', '', '', '', '', '', 'USD', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(13, 10024, 2, 2, 2, 'External', 'Accentrure', 'REF004', 'USA', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(14, 10030, 2, 2, 2, 'External', 'Tata Motors', 'REF004', 'Tata Motors\r\nJamshedpur\r\nIndia', '', '', '', '', '', '', 'inr', '3', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(15, 0, 2, 2, 2, 'External', '', 'REF004', '\r\n            Enter the complete supplier address', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(16, 10032, 2, 2, 2, 'External', '    Microsoft', 'REF004', 'Microsoft', '            Enter the complete supplier address', '', '', '', '', '', 'EUR', '3', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(17, 312321, 2, 2, 2, 'External', '', 'REF004', '                Enter the complete supplier address', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(18, 2312, 2, 2, 2, 'External', 'qwqwe', 'REF004', '                Enter the complete supplier address', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(19, 13221, 2, 2, 2, 'External', 'ssdgs', 'REF004', '                ', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(20, 325325, 2, 2, 2, 'External', '        WIPRO', 'REF004', '                ', '            Enter the complete supplier address', '', '', '', '', '', 'USD', '3', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(21, 10101, 2, 2, 2, 'External', 'KPIT', 'REF004', '                ', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(22, 1223, 2, 2, 2, 'External', 'Cummins', 'REF004', '                ', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0),
(23, 1299129, 2, 2, 2, 'External', 'KPITCummins', 'REF004', '                ', '', '', '', '', '', '', 'inr', '2', 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2017-07-11 00:00:00', 'erew', '2017-07-11 00:00:00', 'y', 0);

-- --------------------------------------------------------

--
-- Table structure for table `supplier_site`
--

CREATE TABLE IF NOT EXISTS `supplier_site` (
  `supplier_site_id` int(11) NOT NULL auto_increment,
  `supplier_id` int(11) NOT NULL,
  `supplier_site_number` int(11) NOT NULL,
  `supplier_site_name` varchar(60) NOT NULL default '',
  `supplier_site_ref` varchar(30) NOT NULL default '',
  `supplier_site_type` varchar(12) default NULL,
  `supplier_site_status` varchar(12) default NULL,
  `supplier_site_profile_id` int(12) default NULL,
  `supplier_site_purchase_id` int(12) default NULL,
  `supplier_site_receipt_id` int(12) default NULL,
  `supplier_site_invoice_id` int(12) NOT NULL default '1',
  `supplier_site_payment_id` int(12) NOT NULL default '1',
  `supplier_site_taxprofile_id` int(12) NOT NULL default '1',
  `supplier_site_address_id` int(12) NOT NULL default '1',
  `supplier_site_contact_id` int(12) NOT NULL default '1',
  `supplier_site_attachement_id` int(12) NOT NULL default '1',
  `supplier_site_eff_id` int(12) default NULL,
  `bu_id` int(12) NOT NULL default '1',
  `bu_shipto_id` int(12) NOT NULL default '1',
  `bu_billto_id` int(12) NOT NULL default '1',
  `bank_id` int(12) default NULL,
  `bank_account_id` int(12) default NULL,
  `liability_account` varchar(15) NOT NULL default '1',
  `payable_account` varchar(15) NOT NULL default '1',
  `payment_discount_account` varchar(15) NOT NULL default '1',
  `pre_payment_account` varchar(15) NOT NULL default '',
  `created_by` varchar(60) NOT NULL default '',
  `creation_date` datetime NOT NULL default '0000-00-00 00:00:00',
  `last_updated_by` varchar(60) NOT NULL default 'admin',
  `last_updation_date` datetime NOT NULL default '0000-00-00 00:00:00',
  `revision_enabled` char(1) default NULL,
  `revision_number` int(11) default NULL,
  PRIMARY KEY  (`supplier_site_id`),
  UNIQUE KEY `supplier_site_number` (`supplier_site_number`),
  KEY `supplier_site_ref` (`supplier_site_ref`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=21 ;

--
-- Dumping data for table `supplier_site`
--

INSERT INTO `supplier_site` (`supplier_site_id`, `supplier_id`, `supplier_site_number`, `supplier_site_name`, `supplier_site_ref`, `supplier_site_type`, `supplier_site_status`, `supplier_site_profile_id`, `supplier_site_purchase_id`, `supplier_site_receipt_id`, `supplier_site_invoice_id`, `supplier_site_payment_id`, `supplier_site_taxprofile_id`, `supplier_site_address_id`, `supplier_site_contact_id`, `supplier_site_attachement_id`, `supplier_site_eff_id`, `bu_id`, `bu_shipto_id`, `bu_billto_id`, `bank_id`, `bank_account_id`, `liability_account`, `payable_account`, `payment_discount_account`, `pre_payment_account`, `created_by`, `creation_date`, `last_updated_by`, `last_updation_date`, `revision_enabled`, `revision_number`) VALUES
(1, 1, 1, '            Mumbai05', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(2, 1, 2, '                Mumbai10', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(3, 2, 1004, '    NewYork1', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '2013-05-11 00:00:00', 'afsafa', '2013-05-11 00:00:00', 'y', 0),
(4, 3, 1005, 'Sedny', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(5, 4, 1006, 'Auckland01', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(6, 4, 10023, 'Lubeck', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(14, 1, 0, '', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(13, 3, 10030, '    Poland01', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(15, 16, 10029, '    US02', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(16, 1, 10043, 'okey', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(17, 10, 100212, 'corrupt', '', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(18, 4, 12321, 'Chennai', 'REF003', '', '', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '', '', '', '', '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(19, 2, 121, 'Rourkela', 'erwe', NULL, NULL, NULL, NULL, NULL, 1, 1, 1, 1, 1, 1, NULL, 1, 1, 1, NULL, NULL, '1', '1', '1', '', '', '0000-00-00 00:00:00', 'admin', '0000-00-00 00:00:00', NULL, NULL),
(20, 4, 132, 'wrwr', 'wrwer', NULL, NULL, NULL, NULL, NULL, 1, 1, 1, 1, 1, 1, NULL, 1, 1, 1, NULL, NULL, '1', '1', '1', '', '', '0000-00-00 00:00:00', 'admin', '0000-00-00 00:00:00', NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `supplier_site1`
--

CREATE TABLE IF NOT EXISTS `supplier_site1` (
  `supplier_site_id` int(11) NOT NULL auto_increment,
  `supplier_id` int(11) NOT NULL,
  `address_id` int(11) NOT NULL,
  `contact_id` int(11) NOT NULL,
  `bank_account_id` int(11) NOT NULL,
  `supplier_site_number` int(11) NOT NULL,
  `supplier_site_type` varchar(60) NOT NULL default '',
  `supplier_site_name` varchar(60) NOT NULL default '',
  `supplier_site_ref` varchar(30) NOT NULL default '',
  `address` tinytext NOT NULL,
  `supp_address` tinytext NOT NULL,
  `gst_no` varchar(25) NOT NULL default '',
  `contact` varchar(60) NOT NULL default '',
  `supp_account_no` varchar(40) NOT NULL default '',
  `website` varchar(100) NOT NULL default '',
  `bank_account` varchar(60) NOT NULL default '',
  `curr_code` char(3) default NULL,
  `payment_terms` int(11) default NULL,
  `tax_included` tinyint(1) NOT NULL default '0',
  `dimension_id` int(11) default '0',
  `dimension2_id` int(11) default '0',
  `tax_group_id` int(11) default NULL,
  `credit_limit` double NOT NULL default '0',
  `purchase_account` varchar(15) NOT NULL default '',
  `payable_account` varchar(15) NOT NULL default '',
  `payment_discount_account` varchar(15) NOT NULL default '',
  `pre_payment_account` varchar(15) NOT NULL default '',
  `notes` tinytext NOT NULL,
  `inactive` tinyint(1) NOT NULL default '0',
  `created_by` varchar(60) NOT NULL default '',
  `creation_date` datetime NOT NULL,
  `last_updated_by` varchar(60) NOT NULL default '',
  `last_updation_date` datetime NOT NULL,
  `revision_enabled` char(1) NOT NULL default 'N',
  `revision_number` int(11) NOT NULL,
  PRIMARY KEY  (`supplier_site_id`),
  UNIQUE KEY `supplier_site_number` (`supplier_site_number`),
  KEY `supplier_site_ref` (`supplier_site_ref`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=18 ;

--
-- Dumping data for table `supplier_site1`
--

INSERT INTO `supplier_site1` (`supplier_site_id`, `supplier_id`, `address_id`, `contact_id`, `bank_account_id`, `supplier_site_number`, `supplier_site_type`, `supplier_site_name`, `supplier_site_ref`, `address`, `supp_address`, `gst_no`, `contact`, `supp_account_no`, `website`, `bank_account`, `curr_code`, `payment_terms`, `tax_included`, `dimension_id`, `dimension2_id`, `tax_group_id`, `credit_limit`, `purchase_account`, `payable_account`, `payment_discount_account`, `pre_payment_account`, `notes`, `inactive`, `created_by`, `creation_date`, `last_updated_by`, `last_updation_date`, `revision_enabled`, `revision_number`) VALUES
(1, 1, 1, 1, 1, 1, 'External', '            Mumbai05', '', '', '', '', '', '', '', '', 'USD', 1, 0, 0, 0, 1, 0, '', '', '', '', '', 0, '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(2, 1, 1, 1, 1, 2, 'External', '                Mumbai10', '', '', '', '', '', '', '', '', 'USD', 1, 0, 0, 0, 1, 0, '', '', '', '', '', 0, '', '2013-05-05 00:00:00', '', '2013-05-05 00:00:00', 'N', 0),
(3, 2, 2, 2, 2, 1004, 'External', '    NewYork1', '', 'PO BOX 1234\r\nNew York\r\nUS - 121313', '', '', '', '', '', '', 'USD', 3, 0, 0, 0, 11, 0, '', '', '', '', '', 0, '', '2013-05-11 00:00:00', 'afsafa', '2013-05-11 00:00:00', 'y', 0),
(4, 3, 0, 0, 0, 1005, 'External', 'Sedny', '', 'Sedny\r\nNSW\r\nBelgium - 412212', '', '', '', '', '', '', 'EUR', 0, 0, 0, 0, 0, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(5, 4, 0, 0, 0, 1006, 'Internal', 'Auckland01', '', 'PO 101\r\nAuckland\r\nNSW\r\nBelgium - 412212', '', '', '', '', '', '', 'INR', 2, 0, 0, 0, 0, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(6, 4, 0, 0, 0, 10023, 'External', 'Lubeck', '', 'Lubeck\r\nGermany', '', '', '', '', '', '', 'EUR', 2, 0, 0, 0, NULL, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(14, 1, 0, 0, 0, 0, 'External', '', '', '            Enter the complete supplier address', '', '', '', '', '', '', 'EUR', 2, 0, 0, 0, NULL, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(13, 3, 0, 0, 0, 10030, 'External', '    Poland01', '', 'Poland', '', '', '', '', '', '', 'USD', 3, 0, 0, 0, NULL, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(15, 16, 0, 0, 0, 10029, 'External', '    US02', '', 'Okey', '', '', '', '', '', '', 'USD', 1, 0, 0, 0, NULL, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(16, 1, 0, 0, 0, 10043, 'External', 'okey', '', '            Enter the complete supplier address', '', '', '', '', '', '', 'EUR', 2, 0, 0, 0, NULL, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0),
(17, 10, 0, 0, 0, 100212, 'External', 'corrupt', '', '            Enter the complete supplier address', '', '', '', '', '', '', 'EUR', 2, 0, 0, 0, NULL, 0, '', '', '', '', '', 0, '', '0000-00-00 00:00:00', '', '0000-00-00 00:00:00', 'N', 0);

-- --------------------------------------------------------

--
-- Table structure for table `system_path`
--

CREATE TABLE IF NOT EXISTS `system_path` (
  `path_id` int(11) NOT NULL auto_increment,
  `path_name` varchar(50) NOT NULL,
  `path_description` varchar(50) default NULL,
  `path_value` varchar(100) default NULL,
  `path_sec_id` int(10) default NULL,
  `path_revision_number` int(10) default NULL,
  `path_revision_enabled` varchar(2) default NULL,
  `path_creation_date` date default NULL,
  `path_created_by` varchar(100) default NULL,
  `path_last_update_date` date default NULL,
  `path_last_updated_by` varchar(100) default NULL,
  PRIMARY KEY  (`path_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=4 ;

--
-- Dumping data for table `system_path`
--

INSERT INTO `system_path` (`path_id`, `path_name`, `path_description`, `path_value`, `path_sec_id`, `path_revision_number`, `path_revision_enabled`, `path_creation_date`, `path_created_by`, `path_last_update_date`, `path_last_updated_by`) VALUES
(1, 'supplier', 'Supplier List', 'modules/ap/suppliers/supplier.php', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(2, 'user registration', 'new user registration', 'extensions/user/user_registration.php', NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(3, 'paths', 'all the paths', 'extensions/path/path.php', NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- --------------------------------------------------------

--
-- Table structure for table `user`
--

CREATE TABLE IF NOT EXISTS `user` (
  `user_id` int(11) NOT NULL auto_increment,
  `person_id` int(12) default NULL,
  `user_name` varchar(60) NOT NULL default '',
  `password` varchar(100) NOT NULL default '',
  `first_name` varchar(100) default NULL,
  `last_name` varchar(60) default NULL,
  `role_id` int(11) NOT NULL default '999',
  `phone` varchar(30) default NULL,
  `email` varchar(100) default NULL,
  `language` varchar(20) default NULL,
  `date_format` tinyint(1) NOT NULL default '0',
  `date_sep` tinyint(1) NOT NULL default '0',
  `tho_sep` tinyint(1) NOT NULL default '0',
  `dec_sep` tinyint(1) NOT NULL default '0',
  `theme` varchar(20) NOT NULL default 'default',
  `page_size` varchar(20) NOT NULL default 'A4',
  `prices_dec` smallint(6) NOT NULL default '2',
  `qty_dec` smallint(6) NOT NULL default '2',
  `rates_dec` smallint(6) NOT NULL default '4',
  `percent_dec` smallint(6) NOT NULL default '1',
  `show_gl` tinyint(1) NOT NULL default '1',
  `show_codes` tinyint(1) NOT NULL default '0',
  `show_hints` tinyint(1) NOT NULL default '0',
  `last_visit_date` datetime default NULL,
  `query_size` tinyint(1) default '10',
  `graphic_links` tinyint(1) default '1',
  `pos` smallint(6) default '1',
  `print_profile` varchar(30) NOT NULL default '1',
  `rep_popup` tinyint(1) default '1',
  `sticky_doc_date` tinyint(1) default '0',
  `startup_tab` varchar(20) default NULL,
  `status` tinyint(1) NOT NULL default '1',
  `created_by` varchar(60) default NULL,
  `creation_date` datetime default NULL,
  `last_updated_by` varchar(60) default NULL,
  `last_updation_date` datetime default NULL,
  `revision_enabled` char(1) default 'N',
  `revision_number` int(11) default NULL,
  PRIMARY KEY  (`user_id`),
  UNIQUE KEY `user_name` (`user_name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=46 ;

--
-- Dumping data for table `user`
--

INSERT INTO `user` (`user_id`, `person_id`, `user_name`, `password`, `first_name`, `last_name`, `role_id`, `phone`, `email`, `language`, `date_format`, `date_sep`, `tho_sep`, `dec_sep`, `theme`, `page_size`, `prices_dec`, `qty_dec`, `rates_dec`, `percent_dec`, `show_gl`, `show_codes`, `show_hints`, `last_visit_date`, `query_size`, `graphic_links`, `pos`, `print_profile`, `rep_popup`, `sticky_doc_date`, `startup_tab`, `status`, `created_by`, `creation_date`, `last_updated_by`, `last_updation_date`, `revision_enabled`, `revision_number`) VALUES
(36, NULL, 'abhik01', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', 'abhik', 'purohit', 1, '', 'abhik@yahoo.com', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, '', 0, '', NULL, '', NULL, 'N', NULL),
(43, 100, 'nishitdas', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', '', '', 1, NULL, 'nishitdas@yahoo.co.in', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, 'inoerp', '2005-06-13 16:28:53', NULL, NULL, 'N', NULL),
(34, NULL, 'inoerp', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', '', NULL, 1, '', 'ndas.oracle@gmail.com', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, '', 0, '', NULL, '', NULL, 'N', NULL),
(37, 100, 'sachin', 'zxcvbnm1', 'sachin', 'tendulkar', 1, NULL, 'sachin@yahoo.co.in', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, NULL, NULL, NULL, NULL, 'N', NULL),
(38, 100, 'sourav', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', 'sachin', 'tendulkar', 1, NULL, 'sourav@yahoo.co.in', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, NULL, NULL, NULL, NULL, 'N', NULL),
(39, 100, 'manish', '6c3a75f95ea43b54f3eaf05d8df078a59722fa5876fe11a17cb608ff325da025', 'sachin', 'tendulkar', 1, NULL, 'manish@yahoo.co.in', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, NULL, NULL, NULL, NULL, 'N', NULL),
(40, 100, 'abhinab', '4b00e4469e865ec5b5ba7a18b3111533b632c2b49faf3dbb2e30fdd463b4a9c4', 'sachin', 'tendulkar', 1, NULL, 'abhinab@yahoo.co.in', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, NULL, NULL, NULL, NULL, 'N', NULL),
(41, 100, 'dravid', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', 'sachin', 'tendulkar', 1, NULL, 'dravid@yahoo.co.in', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, NULL, NULL, NULL, NULL, 'N', NULL),
(42, 100, 'dhoni1', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', 'sachin', 'tendulkar', 1, NULL, 'dhoni@yahoo.com', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, 'dravid', '2025-05-13 15:38:51', NULL, NULL, 'N', NULL),
(44, 100, 'erewe', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', '', '', 1, NULL, 'erewe@yahoo.com', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, 'inoerp', '2011-06-13 17:34:02', NULL, NULL, 'N', NULL),
(45, 100, 'abcdefgh', '67796beda3b66b27ec80739f4b07301b253e5fdee5e3019d9e6f942dcedfba19', '', '', 1, NULL, 'abc@rediff.com', NULL, 0, 0, 0, 0, 'default', 'A4', 2, 2, 4, 1, 1, 0, 0, NULL, 10, 1, 1, '1', 1, 0, NULL, 0, 'inoerp', '2015-06-13 09:16:22', NULL, NULL, 'N', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `xxx_enterprise`
--

CREATE TABLE IF NOT EXISTS `xxx_enterprise` (
  `enterprise_id` int(12) NOT NULL auto_increment,
  `name` varchar(50) NOT NULL,
  `description` varchar(200) default NULL,
  `address_id` int(12) default NULL,
  `created_by` varchar(50) default NULL,
  `creation_date` varchar(50) default NULL,
  `last_update_by` varchar(50) default NULL,
  `last_update_date` varchar(50) default NULL,
  PRIMARY KEY  (`enterprise_id`),
  UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=31 ;

--
-- Dumping data for table `xxx_enterprise`
--

INSERT INTO `xxx_enterprise` (`enterprise_id`, `name`, `description`, `address_id`, `created_by`, `creation_date`, `last_update_by`, `last_update_date`) VALUES
(9, 'TEST51', 'TEST51', 1, 'inoerp', '13-06-2013 02:52:45', 'inoerp', '13-06-2013 02:52:45'),
(7, 'TEST25', 'TEST25', 0, 'inoerp', '12-06-2013 15:37:39', 'inoerp', '12-06-2013 15:37:39'),
(8, 'TEST50', 'TEST50', 0, 'inoerp', '13-06-2013 02:51:00', 'inoerp', '13-06-2013 02:51:00'),
(10, 'TEST52', 'TEST52', 0, 'inoerp', '13-06-2013 03:17:13', 'inoerp', '13-06-2013 03:17:13'),
(11, 'TEST53', 'TEST53', 1, 'inoerp', '13-06-2013 03:18:18', 'inoerp', '13-06-2013 03:18:18'),
(12, 'TEST54', 'TEST54', 1, 'inoerp', '13-06-2013 05:14:02', 'inoerp', '13-06-2013 05:14:02'),
(13, 'test55', 'test55', 0, 'inoerp', '13-06-2013 05:16:42', 'inoerp', '13-06-2013 05:16:42'),
(14, 'TEST56', 'TEST56', 0, 'inoerp', '13-06-2013 05:26:54', 'inoerp', '13-06-2013 05:26:54'),
(15, 'TEST60', 'TEST60', 0, 'inoerp', '13-06-2013 07:05:23', 'inoerp', '13-06-2013 07:05:23'),
(16, 'TEST61', 'TEST61', 0, 'inoerp', '13-06-2013 07:10:05', 'inoerp', '13-06-2013 07:10:05'),
(17, 'TEST62', 'TEST62', 1, 'inoerp', '13-06-2013 07:10:54', 'inoerp', '13-06-2013 07:10:54'),
(18, 'TEST65', 'TEST65', 0, 'inoerp', '13-06-2013 07:12:14', 'inoerp', '13-06-2013 07:12:14'),
(19, 'TEST66', 'TEST66', 1, 'inoerp', '13-06-2013 07:23:07', 'inoerp', '13-06-2013 07:23:07'),
(20, 'test70', 'test70', 1, 'inoerp', '13-06-2013 09:12:58', 'inoerp', '13-06-2013 09:12:58'),
(21, 'TEST80', 'TEST80', 0, 'inoerp', '13-06-2013 09:19:17', 'inoerp', '13-06-2013 09:19:17'),
(22, 'TEST81', 'TEST81', 1, 'inoerp', '13-06-2013 09:21:06', 'inoerp', '13-06-2013 09:21:06'),
(23, 'TEST84', 'TEST84', 1, 'inoerp', '13-06-2013 09:23:07', 'inoerp', '13-06-2013 09:23:07'),
(24, 'TEST85', 'TEST85', 1, 'inoerp', '13-06-2013 09:27:47', 'inoerp', '13-06-2013 09:27:47'),
(25, 'TEST90', 'TEST90', 1, 'inoerp', '13-06-2013 10:38:19', 'inoerp', '13-06-2013 10:38:19'),
(26, 'TEST100', 'TEST100', 0, 'inoerp', '13-06-2013 13:49:00', 'inoerp', '13-06-2013 13:49:00'),
(27, 'TEST101', 'TEST101', 0, 'inoerp', '13-06-2013 13:52:45', 'inoerp', '13-06-2013 13:52:45'),
(28, 'test102', 'test102', 0, 'inoerp', '13-06-2013 13:57:11', 'inoerp', '13-06-2013 13:57:11'),
(29, 'TEST500', 'TEST500AAA', 1, 'inoerp', '14-06-2013 11:36:47', 'inoerp', '14-06-13 12:08:21'),
(30, 'cat4mba', 'test01', 0, 'inoerp', '14-06-2013 11:37:19', 'inoerp', '14-06-2013 11:37:19');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
