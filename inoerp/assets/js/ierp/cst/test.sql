CREATE DEFINER = `root` @`localhost` FUNCTION `wipUpdateWoLineQuantity`(
    fromWipWoLineId INT,
    toWipWoLineId INT,
    fromOperationStep VARCHAR(30),
    toOperationStep VARCHAR(30),
    moveQuantity DECIMAL
) RETURNS int BEGIN
DECLARE fromColumnName VARCHAR(100);
DECLARE newFromQty DECIMAL;
DECLARE toColumnName VARCHAR(100);
DECLARE newToQty DECIMAL;
/*update from ops quantity*/
IF(fromOperationStep = 'queue') THEN
SET fromColumnName = 'queue_quantity';
ELSE IF(fromOperationStep = 'running') THEN
SET fromColumnName = 'running_quantity';
ELSE IF(fromOperationStep = 'completed') THEN
SET fromColumnName = 'completed_quantity';
ELSE IF(fromOperationStep = 'rejected') THEN
SET fromColumnName = 'rejected_quantity_quantity';
ELSE RETURN 0;
END IF;
END IF;
END IF;
END IF;
SELECT (ifnull(fromColumnName, 0) - moveQuantity) INTO newFromQty
WHERE wip_wo_line_id = fromWipWoLineId;
UPDATE wip_wo_line
SET fromColumnName = newFromQty
WHERE wip_wo_line_id = fromWipWoLineId;
/*update to ops quantity*/
IF(toOperationStep = 'scrapped') THEN
SET toColumnName = 'scrapped_quantity';
ELSE IF(toOperationStep = 'running') THEN
SET toColumnName = 'running_quantity';
ELSE IF(toOperationStep = 'completed') THEN
SET toColumnName = 'completed_quantity';
ELSE IF(toOperationStep = 'rejected') THEN
SET toColumnName = 'rejected_quantity_quantity';
ELSE
SET toColumnName = 'queue_quantity';
END IF;
END IF;
END IF;
END IF;
SELECT (ifnull(toColumnName, 0) + moveQuantity) INTO newToQty
WHERE wip_wo_line_id = fromWipWoLineId;
UPDATE wip_wo_line
SET toColumnName = newToQty
WHERE wip_wo_line_id = fromWipWoLineId;
RETURN 1;
END