Function.prototype.bind = function(obj)
{
	var fn = this;
	return function()
	{
		return fn.apply(obj, arguments);
	};
};

Array.prototype.remove = function(obj)
{
	var i = this.length;
	while (i--)
	{
		if (this[i] == obj)
		{
			this.splice(i, 1);
		}
	}
};

Array.prototype.contains = function(obj)
{
	var i = this.length;
	while (i--)
	{
		if (this[i] == obj)
		{
			return true;
		}
	}
	return false;
};

var Point = function(x, y)
{
	this.x = x;
	this.y = y;
}

var Rectangle = function(x, y, width, height)
{
	this.x = x;
	this.y = y;
	this.width = width;
	this.height = height;
};

Rectangle.prototype.contains = function(point)
{
	return ((point.x >= this.x) && (point.x <= (this.x + this.width)) && (point.y >= this.y) && (point.y <= (this.y + this.height)));
};

Rectangle.prototype.inflate = function(dx, dy)
{
	this.x -= dx;
	this.y -= dy;
	this.width += dx + dx + 1;
	this.height += dy + dy + 1;
};

Rectangle.prototype.union = function(rectangle)
{
	var x1 = (this.x < rectangle.x) ? this.x : rectangle.x;
	var y1 = (this.y < rectangle.y) ? this.y : rectangle.y;
	var x2 = ((this.x + this.width) < (rectangle.x + rectangle.width)) ? (rectangle.x + rectangle.width) : (this.x + this.width);
	var y2 = ((this.y + this.height) < (rectangle.y + rectangle.height)) ? (rectangle.y + rectangle.height) : (this.y + this.height);
	return new Rectangle(x1, y1, x2 - x1, y2 - y1);
};

Rectangle.prototype.topLeft = function()
{
	return new Point(this.x, this.y);
};

CanvasRenderingContext2D.prototype.dashedLine = function(x1, y1, x2, y2)
{
	this.moveTo(x1, y1);
	var dx = x2 - x1;
	var dy = y2 - y1;
	var count = Math.floor(Math.sqrt(dx * dx + dy * dy) / 3); // dash length
	var ex = dx / count;
	var ey = dy / count;

	var q = 0;
	while (q++ < count) 
	{
		x1 += ex;
		y1 += ey;
		if (q % 2 === 0)
		{ 
			this.moveTo(x1, y1);
		}
		else
		{
			this.lineTo(x1, y1);
		}
	}
	if (q % 2 === 0)
	{
		this.moveTo(x2, y2);
	}
	else
	{
		this.lineTo(x2, y2);
	}
};

CanvasRenderingContext2D.prototype.roundedRect = function(x, y, width, height, radius)
{
  this.beginPath();
  this.moveTo(x + radius, y);
  this.lineTo(x + width - radius, y);
  this.quadraticCurveTo(x + width, y, x + width, y + radius);
  this.lineTo(x + width, y + height - radius);
  this.quadraticCurveTo(x + width, y + height, x + width - radius, y + height);
  this.lineTo(x + radius, y + height);
  this.quadraticCurveTo(x, y + height, x, y + height - radius);
  this.lineTo(x, y + radius);
  this.quadraticCurveTo(x, y, x + radius, y);
  this.closePath();
};

var Cursors = 
{
	arrow: "default",
	grip: "pointer", // "crosshair", 
	cross: "pointer", // "crosshair",
	move: "move", 
	select: "pointer" 
};

var Connector = function(owner, template)
{
	this.owner = owner;
	this.template = template;
	this.connections = [];
	this.hover = false;
};

Connector.prototype.getCursor = function(point)
{
	return Cursors.grip;
};

Connector.prototype.hitTest = function(rectangle)
{
	if ((rectangle.width === 0) && (rectangle.height === 0))
	{
		return this.getRectangle().contains(rectangle.topLeft());
	}
	return rectangle.contains(this.getRectangle());
};

Connector.prototype.getRectangle = function()
{
	var point = this.owner.getConnectorPosition(this);
	var rectangle = new Rectangle(point.x, point.y, 0, 0);
	rectangle.inflate(3, 3);
	return rectangle;
};

Connector.prototype.invalidate = function()
{
};

Connector.prototype.isValid = function(value)
{
	if (value === this)
	{
		return false;
	}
	var t1 = this.template.type.split(' ');
	if (!t1.contains("[array]") && (this.connections.length == 1))
	{
		return false;
	}
	if (value instanceof Connector)
	{	
		var t2 = value.template.type.split(' ');
		if ((t1[0] != t2[0]) ||
		(this.owner == value.owner) || 
			(t1.contains("[in]") && !t2.contains("[out]")) || 
			(t1.contains("[out]") && !t2.contains("[in]")) || 
			(!t2.contains("[array]") && (value.connections.length == 1)))
		{
			return false;
		}
	}
	return true;
};

Connector.prototype.paint = function(context, other)
{
	var rectangle = this.getRectangle();
	var strokeStyle = this.owner.owner.theme.connectorBorder; 
	var fillStyle = this.owner.owner.theme.connector;
	if (this.hover)
	{
		strokeStyle = this.owner.owner.theme.connectorHoverBorder; 
		fillStyle = this.owner.owner.theme.connectorHover;
		if (!this.isValid(other))
		{
			fillStyle = "#f00";			
		}
	}

	context.lineWidth = 1;
	context.strokeStyle = strokeStyle;
	context.lineCap = "butt";
	context.fillStyle = fillStyle;
	context.fillRect(rectangle.x - 0.5, rectangle.y - 0.5, rectangle.width, rectangle.height);
	context.strokeRect(rectangle.x - 0.5, rectangle.y - 0.5, rectangle.width, rectangle.height);

	if (this.hover)
	{
		// Tooltip for Connector point
		var text = ("description" in this.template) ? this.template.description : this.template.name;
		context.textBaseline = "bottom";
		context.font = "8.25pt Tahoma";
		var size = context.measureText(text);
		size.height = 14;
		var a = new Rectangle(rectangle.x - Math.floor(size.width / 2), rectangle.y + size.height + 6, size.width, size.height);
		var b = new Rectangle(a.x, a.y, a.width, a.height);
		a.inflate(4, 1);
		context.fillStyle = "rgb(255, 255, 231)";
		context.fillRect(a.x - 0.5, a.y - 0.5, a.width, a.height);
		context.strokeStyle = "#000";
		context.lineWidth = 1;
		context.strokeRect(a.x - 0.5, a.y - 0.5, a.width, a.height);
		context.fillStyle = "#000";
		context.fillText(text, b.x, b.y + 13);
	}
};

var Tracker = function(rectangle, resizable)
{
	this.rectangle = new Rectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
	this.resizable = resizable;
	this.track = false;
};

Tracker.prototype.hitTest = function(point)
{
	// (0, 0) element, (-1, -1) top-left, (+1, +1) bottom-right
	if (this.resizable)
	{
		for (var x = -1; x <= +1; x++)
		{
			for (var y = -1; y <= +1; y++)
			{
				if ((x !== 0) || (y !== 0))
				{
					var hit = new Point(x, y);
					if (this.getGripRectangle(hit).contains(point))
					{
						return hit;
					}
				}
			}
		}
	}

	if (this.rectangle.contains(point))
	{
		return new Point(0, 0);
	}

	return new Point(-2, -2);
};

Tracker.prototype.getGripRectangle = function(point)
{
	var r = new Rectangle(0, 0, 7, 7);
	if (point.x <   0) { r.x = this.rectangle.x - 7; }
	if (point.x === 0) { r.x = this.rectangle.x + Math.floor(this.rectangle.width / 2) - 3; }
	if (point.x >   0) { r.x = this.rectangle.x + this.rectangle.width + 1; }
	if (point.y <   0) { r.y = this.rectangle.y - 7; }
	if (point.y === 0) { r.y = this.rectangle.y + Math.floor(this.rectangle.height / 2) - 3; }
	if (point.y >   0) { r.y = this.rectangle.y + this.rectangle.height + 1; }
	return r;
};

Tracker.prototype.getCursor = function(point)
{
	var hit = this.hitTest(point);
	if ((hit.x === 0) && (hit.y === 0))
	{
		return (this.track) ? Cursors.move : Cursors.select;
	}
	if ((hit.x >= -1) && (hit.x <= +1) && (hit.y >= -1) && (hit.y <= +1) && this.resizable) 
	{
		if (hit.x === -1 && hit.y === -1) { return "nw-resize"; }
		if (hit.x === +1 && hit.y === +1) { return "se-resize"; }
		if (hit.x === -1 && hit.y === +1) { return "sw-resize"; }
		if (hit.x === +1 && hit.y === -1) { return "ne-resize"; }
		if (hit.x ===  0 && hit.y === -1) { return "n-resize";  }
		if (hit.x ===  0 && hit.y === +1) { return "s-resize";  }
		if (hit.x === +1 && hit.y ===  0) { return "e-resize";  }
		if (hit.x === -1 && hit.y ===  0) { return "w-resize";  }
	}
	return null;
};

Tracker.prototype.start = function(point, handle)
{
	if ((handle.x >= -1) && (handle.x <= +1) && (handle.y >= -1) && (handle.y <= +1))
	{
		this.handle = handle;
		this.currentPoint = point;
		this.track = true;
	}
};

Tracker.prototype.move = function(point)
{
	var h = this.handle;
	var a = new Point(0, 0);
	var b = new Point(0, 0);
	if ((h.x == -1) || ((h.x === 0) && (h.y === 0))) { a.x = point.x - this.currentPoint.x; }
	if ((h.y == -1) || ((h.x === 0) && (h.y === 0))) { a.y = point.y - this.currentPoint.y; }
	if ((h.x == +1) || ((h.x === 0) && (h.y === 0))) { b.x = point.x - this.currentPoint.x; }
	if ((h.y == +1) || ((h.x === 0) && (h.y === 0))) { b.y = point.y - this.currentPoint.y; }
	var tl = new Point(this.rectangle.x, this.rectangle.y);
	var br = new Point(this.rectangle.x + this.rectangle.width, this.rectangle.y + this.rectangle.height);
	tl.x += a.x;
	tl.y += a.y;
	br.x += b.x;
	br.y += b.y;
	this.rectangle.x = tl.x;
	this.rectangle.y = tl.y;
	this.rectangle.width = br.x - tl.x;
	this.rectangle.height = br.y - tl.y;
	this.currentPoint = point;
};

Tracker.prototype.paint = function(context)
{
	if (this.resizable)
	{
		for (var x = -1; x <= +1; x++)
		{
			for (var y = -1; y <= +1; y++)
			{
				if ((x !== 0) || (y !== 0))
				{
					var rectangle = this.getGripRectangle(new Point(x, y));
					context.fillStyle = "#ffffff";
					context.strokeStyle = "#000000";
					context.lineWidth = 1;
					context.fillRect(rectangle.x - 0.5, rectangle.y - 0.5, rectangle.width - 1, rectangle.height - 1);
					context.strokeRect(rectangle.x - 0.5, rectangle.y - 0.5, rectangle.width - 1, rectangle.height - 1);
				}
			}
		}
	}
};

var Element = function(template, point)
{
	this.template = template;
	this.rectangle = new Rectangle(point.x, point.y, template.defaultWidth, template.defaultHeight);
	this.content = template.defaultContent;
	this.text = '';
	this.userinput = 0;
	this.sinks = 0;
	this.vuln = 0;
	this.owner = null;
	this.hover = false;
	this.selected = false;
	this.tracker = null;
	this.connectors = [];
	for (var i = 0; i < template.connectorTemplates.length; i++)
	{
		var connectorTemplate = template.connectorTemplates[i];
		this.connectors.push(new Connector(this, connectorTemplate));
	}	
};

Element.prototype.select = function()
{
	this.hover = false;
	this.selected = true;
	this.tracker = new Tracker(this.rectangle, ("resizable" in this.template) ? this.template.resizable : false);
	this.invalidate();
};

Element.prototype.deselect = function()
{
	this.selected = false;
	this.invalidate();
	this.tracker = null;
};

Element.prototype.getRectangle = function()
{
	return ((this.tracker !== null) && (this.tracker.track)) ? this.tracker.rectangle : this.rectangle;
};

Element.prototype.getPageRectangle = function()
{
	var rectangle = this.getRectangle();
	rectangle = new Rectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
	var canvas = this.owner.canvas;
	rectangle.x += canvas.offsetLeft;
	rectangle.y += canvas.offsetTop;
	return rectangle;
};

Element.prototype.setRectangle = function(rectangle)
{
	this.invalidate();
	this.rectangle = rectangle;
	if (this.tracker !== null)
	{
		this.tracker.rectangle = new Rectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
	}
	this.invalidate();
};

Element.prototype.paint = function(context)
{
	this.template.paint(this, context);
	
	if (this.selected)
	{
		this.tracker.paint(context);
	}
	
	// mark all connections by mouseover
	if(this.hover || this.selected)
	{
		for (var i = 0; i < this.connectors[1].connections.length; i++)
		{
			this.connectors[1].connections[i].lineWidth = 2;
			if(this.connectors[1].connections[i].color != '#F00')
				this.connectors[1].connections[i].color = '#00F';
		}	
	} else
	{
		for (var i = 0; i < this.connectors[1].connections.length; i++)
		{
			this.connectors[1].connections[i].lineWidth = 1;
			if(this.connectors[1].connections[i].color != '#F00')
				this.connectors[1].connections[i].color = '#000';
		}	
	}
	
	var rectangle = this.getRectangle();
	lines = this.text.split(",");
	context.textBaseline = "bottom";
	context.font = "8.25pt Tahoma";
	context.fillStyle = "#000";
	context.fillText(lines[0], rectangle.x + 5, rectangle.y + 13 + 20);
	
	// userinput DOT
	context.beginPath();
	context.fillStyle = "#FFF";
	context.arc(rectangle.x + this.template.defaultWidth-15,rectangle.y + this.template.defaultHeight-11,((this.userinput > 9) ? 9 : this.userinput),0,Math.PI*2,true);
	context.fill();
	context.closePath();
	
	context.beginPath();
	context.strokeStyle = "#000";
	context.lineWidth = 1;
	context.arc(rectangle.x + this.template.defaultWidth-15,rectangle.y + this.template.defaultHeight-11,((this.userinput > 9) ? 9 : this.userinput),0,Math.PI*2,true);
	context.stroke();
	context.closePath();
	
	// sensitive sink DOT
	context.beginPath();
	context.fillStyle = this.vuln ? "red" : "#FFCE42";
	context.arc(rectangle.x + this.template.defaultWidth-35,rectangle.y + this.template.defaultHeight-11,((this.sinks > 9) ? 9 : this.sinks),0,Math.PI*2,true);
	context.fill();
	context.closePath();
	
	context.beginPath();
	context.strokeStyle = "#000";
	context.lineWidth = 1;
	context.arc(rectangle.x + this.template.defaultWidth-35,rectangle.y + this.template.defaultHeight-11,((this.sinks > 9) ? 9 : this.sinks),0,Math.PI*2,true);
	context.stroke();
	context.closePath();	
	
	if (this.hover)
	{
		// Tooltip for Element
		if(this.content.length > 20)
		{
			context.textBaseline = "bottom";
			context.font = "8.25pt Tahoma";
			var size = context.measureText(this.content);
			size.height = 14;
			var a = new Rectangle(rectangle.x, rectangle.y -20, size.width, size.height);
			var b = new Rectangle(a.x, a.y, a.width, a.height);
			a.inflate(4, 1);
			context.fillStyle = "rgb(255, 255, 231)";
			context.fillRect(a.x, a.y, a.width, a.height);
			context.strokeStyle = "#000";
			context.lineWidth = 1;
			context.strokeRect(a.x , a.y, a.width, a.height);
			context.fillStyle = "#000";
			context.fillText(this.content, b.x, b.y + 13);
		}
		
		/*
		// enlarge element to view whole text
		var size = context.measureText(this.text);
		size.height = 14;
		var a = new Rectangle(rectangle.x + 4.5, rectangle.y + size.height + 4.5, this.template.defaultWidth-9, this.template.defaultHeight-20 + lines.length*15 - 18);
		var b = new Rectangle(a.x, a.y+1, a.width, a.height);
		a.inflate(4, 1);
		context.fillStyle = "#ddd";
		context.fillRect(a.x - 0.5, a.y - 0.5, a.width, a.height);
		context.strokeStyle = "#246";
		context.lineWidth = 2;
		context.strokeRect(a.x - 0.5, a.y - 0.5, a.width, a.height);
		context.fillStyle = "#000";
		for (var i = 0; i<lines.length; i++)
			context.fillText(lines[i], b.x, b.y + 13 + (i*15));
		*/	
	}

};

Element.prototype.invalidate = function()
{
};

Element.prototype.insertInto = function(owner)
{
	this.owner = owner;
	this.owner.elements.push(this);
};

Element.prototype.remove = function()
{
	this.invalidate();

	for (var i = 0; i < this.connectors.length; i++)
	{
		var connections = this.connectors[i].connections;
		for (var j = 0; j < connections.length; j++)
		{
			connections[j].remove();
		}
	}
	
	if ((this.owner !== null) && (this.owner.elements.contains(this)))
	{
		this.owner.elements.remove(this);
	}

	this.owner = null;
};

Element.prototype.hitTest = function(rectangle)
{
	if ((rectangle.width === 0) && (rectangle.height === 0))
	{
		if (this.rectangle.contains(rectangle.topLeft()))
		{
			return true;
		}

		if ((this.tracker !== null) && (this.tracker.track))
		{
			var h = this.tracker.hitTest(rectangle.topLeft());
			if ((h.x >= -1) && (h.x <= +1) && (h.y >= -1) && (h.y <= +1))
			{
				return true;
			}
		}

		for (var i = 0; i < this.connectors.length; i++)
		{
			if (this.connectors[i].hitTest(rectangle))
			{
				return true;
			}
		}

		return false;
	}

	return rectangle.contains(this.rectangle);
};

Element.prototype.getCursor = function(point)
{
	if (this.tracker !== null)
	{
		var cursor = this.tracker.getCursor(point);
		if (cursor !== null)
		{
			return cursor;
		}
	}

	/*if (window.event.shiftKey)
	{
		return Cursors.add;
	}*/

	return Cursors.select;
};

Element.prototype.getConnector = function(name)
{
	for (var i = 0; i < this.connectors.length; i++)
	{
		var connector = this.connectors[i];
		if (connector.template.name == name)
		{
			return connector;
		}
	}
	return null;
};

Element.prototype.getConnectorPosition = function(connector)
{
	var rectangle = this.getRectangle();
	var point = connector.template.position(this);
	point.x += rectangle.x;
	point.y += rectangle.y;
	return point;
};

Element.prototype.setContent = function(content)
{
	this.owner.setElementContent(this, content);
};

Element.prototype.getContent = function()
{
	return this.content;
};

/* -------------------------- connection ------------------- */

var Connection = function(from, to)
{
	this.from = from;
	this.to = to;
	this.toPoint = null;
	this.color = '#000';
	this.lineWidth = 1;
};

Connection.prototype.select = function()
{
	this.selected = true;
	this.invalidate();
};

Connection.prototype.deselect = function()
{
	this.selected = false;
	this.invalidate();
};

Connection.prototype.remove = function()
{
	this.invalidate();
	if ((this.from !== null) && (this.from.connections.contains(this)))
	{
		this.from.connections.remove(this);
	}
	if ((this.to !== null) && (this.to.connections.contains(this)))
	{
		this.to.connections.remove(this);
	}
	this.from = null;
	this.to = null;
};

Connection.prototype.insert = function(from, to)
{
	this.from = from;
	this.to = to;
	this.from.connections.push(this);
	this.from.invalidate();
	this.to.connections.push(this);
	this.to.invalidate();
	this.invalidate();
};

Connection.prototype.getCursor = function(point)
{
	return Cursors.select;
};

Connection.prototype.hitTest = function(rectangle)
{
	if ((this.from !== null) && (this.to !== null))
	{
		var p1 = this.from.owner.getConnectorPosition(this.from);
		var p2 = this.to.owner.getConnectorPosition(this.to);
		if ((rectangle.width !== 0) || (rectangle.height !== 0))
		{
			return (rectangle.contains(p1) && rectangle.contains(p2));
		}
		
		var p = rectangle.topLeft();

		// p1 must be the leftmost point
		if (p1.x > p2.x) { var temp = p2; p2 = p1; p1 = temp; }

		var r1 = new Rectangle(p1.x, p1.y, 0, 0);
		var r2 = new Rectangle(p2.x, p2.y, 0, 0);
		r1.inflate(3, 3);
		r2.inflate(3, 3);

		if (r1.union(r2).contains(p))
		{
			if ((p1.x == p2.x) || (p1.y == p2.y)) // straight line
			{
				return true;
			}
			else if (p1.y < p2.y)
			{
				var o1 = r1.x + (((r2.x - r1.x) * (p.y - (r1.y + r1.height))) / ((r2.y + r2.height) - (r1.y + r1.height)));
				var u1 = (r1.x + r1.width) + ((((r2.x + r2.width) - (r1.x + r1.width)) * (p.y - r1.y)) / (r2.y - r1.y));
				return ((p.x > o1) && (p.x < u1));
			}
			else
			{
				var o2 = r1.x + (((r2.x - r1.x) * (p.y - r1.y)) / (r2.y - r1.y));
				var u2 = (r1.x + r1.width) + ((((r2.x + r2.width) - (r1.x + r1.width)) * (p.y - (r1.y + r1.height))) / ((r2.y + r2.height) - (r1.y + r1.height)));
				return ((p.x > o2) && (p.x < u2));
			}
		}
	}
	return false;
};

Connection.prototype.invalidate = function()
{
	if (this.from !== null)
	{
		this.from.invalidate();
	}
	if (this.to !== null)
	{
		this.to.invalidate();
	}
};

Connection.prototype.paint = function(context)
{
	context.strokeStyle = this.color;
	context.lineWidth = (this.hover) ? 2 : this.lineWidth;
	this.paintLine(context, this.selected);
};

Connection.prototype.paintTrack = function(context)
{
	context.strokeStyle = this.from.owner.owner.theme.connection;
	context.lineWidth = 1;
	this.paintLine(context, true);
};

Connection.prototype.paintLine = function(context, dashed)
{
	if (this.from !== null)
	{
		var start = this.from.owner.getConnectorPosition(this.from);
		var end = (this.to !== null) ? this.to.owner.getConnectorPosition(this.to) : this.toPoint;
		if ((start.x != end.x) || (start.y != end.y))
		{
			context.beginPath();
			if (dashed)
			{
				context.dashedLine(start.x, start.y, end.x, end.y);
			}
			else
			{
				context.moveTo(start.x - 0.5, start.y - 0.5);
				context.lineTo(end.x - 0.5, end.y - 0.5);
			}
			context.closePath();
			context.stroke();
		}
	}
};

var Selection = function(startPoint)
{
	this.startPoint = startPoint;
	this.currentPoint = startPoint;
};

Selection.prototype.paint = function(context)
{
	var r = this.getRectangle();
	context.lineWidth = 1;
	context.beginPath();
	context.dashedLine(r.x - 0.5,           r.y - 0.5,            r.x - 0.5 + r.width, r.y - 0.5);
	context.dashedLine(r.x - 0.5 + r.width, r.y - 0.5,            r.x - 0.5 + r.width, r.y - 0.5 + r.height);
	context.dashedLine(r.x - 0.5 + r.width, r.y - 0.5 + r.height, r.x - 0.5,           r.y - 0.5 + r.height);
	context.dashedLine(r.x - 0.5,           r.y - 0.5 + r.height, r.x - 0.5,           r.y - 0.5);
	context.closePath();
	context.stroke();
};

Selection.prototype.getRectangle = function()
{
	var r = new Rectangle(
		(this.startPoint.x <= this.currentPoint.x) ? this.startPoint.x : this.currentPoint.x,
		(this.startPoint.y <= this.currentPoint.y) ? this.startPoint.y : this.currentPoint.y,
		this.currentPoint.x - this.startPoint.x,
		this.currentPoint.y - this.startPoint.y);
	if (r.width < 0) 
	{
		r.width *= -1;
	}
	if (r.height < 0) 
	{
		r.height *= -1;
	}
	return r;
};

var ContainerUndoUnit = function()
{
	this.undoUnits = [];
};

ContainerUndoUnit.prototype.add = function(undoUnit)
{
	this.undoUnits.push(undoUnit);
};

ContainerUndoUnit.prototype.undo = function()
{
	for (var i = 0; i < this.undoUnits.length; i++)
	{
		this.undoUnits[i].undo();
	}
};

ContainerUndoUnit.prototype.redo = function()
{
	for (var i = 0; i < this.undoUnits.length; i++)
	{
		this.undoUnits[i].redo();
	}
};

ContainerUndoUnit.prototype.isEmpty = function()
{
	if (this.undoUnits.length > 0)
	{
		for (var i = 0; i < this.undoUnits.length; i++)
		{
			if (!("isEmpty" in this.undoUnits[i]) || !this.undoUnits[i].isEmpty())
			{
				return false;
			}
		}
	}
	return true;
};

var InsertElementUndoUnit = function(element, owner)
{
	this.element = element;
	this.owner = owner;
};

InsertElementUndoUnit.prototype.undo = function()
{
	this.element.remove();
};

InsertElementUndoUnit.prototype.redo = function()
{
	this.element.insertInto(this.owner);
};

var DeleteElementUndoUnit = function(element)
{
	this.element = element;
	this.owner = this.element.owner;
};

DeleteElementUndoUnit.prototype.undo = function()
{
	this.element.insertInto(this.owner);
};

DeleteElementUndoUnit.prototype.redo = function()
{
	this.element.remove();
};

var InsertConnectionUndoUnit = function(connection, from, to)
{
	this.connection = connection;
	this.from = from;
	this.to = to;
};

InsertConnectionUndoUnit.prototype.undo = function()
{
	this.connection.remove();
};

InsertConnectionUndoUnit.prototype.redo = function()
{
	this.connection.insert(this.from, this.to);
};

var DeleteConnectionUndoUnit = function(connection)
{
	this.connection = connection;
	this.from = connection.from;
	this.to = connection.to;
};

DeleteConnectionUndoUnit.prototype.undo = function()
{
	this.connection.insert(this.from, this.to);
};

DeleteConnectionUndoUnit.prototype.redo = function()
{
	this.connection.remove();
};

var ContentChangedUndoUnit = function(element, content)
{
	this.element = element;
	this.undoContent = element.content;
	this.redoContent = content;
};

ContentChangedUndoUnit.prototype.undo = function()
{
	this.element.content = this.undoContent;
};

ContentChangedUndoUnit.prototype.redo = function()
{
	this.element.content = this.redoContent;
};

var TransformUndoUnit = function(element, undoRectangle, redoRectangle)
{
	this.element = element;
	this.undoRectangle = new Rectangle(undoRectangle.x, undoRectangle.y, undoRectangle.width, undoRectangle.height);
	this.redoRectangle = new Rectangle(redoRectangle.x, redoRectangle.y, redoRectangle.width, redoRectangle.height);
};

TransformUndoUnit.prototype.undo = function()
{
	this.element.setRectangle(this.undoRectangle);
};

TransformUndoUnit.prototype.redo = function()
{
	this.element.setRectangle(this.redoRectangle);
};

var SelectionUndoUnit = function()
{
	this.states = [];
};

SelectionUndoUnit.prototype.undo = function()
{
	for (var i = 0; i < this.states.length; i++)
	{
		if (this.states[i].undo)
		{
			this.states[i].value.select();
		}
		else
		{
			this.states[i].value.deselect();
		}
	}
};

SelectionUndoUnit.prototype.redo = function()
{
	for (var i = 0; i < this.states.length; i++)
	{
		if (this.states[i].redo)
		{
			this.states[i].value.select();
		}
		else
		{
			this.states[i].value.deselect();
		}
	}
};

SelectionUndoUnit.prototype.select = function(value)
{
	this.update(value, value.selected, true);
};

SelectionUndoUnit.prototype.deselect = function(value)
{
	this.update(value, value.selected, false);
};

SelectionUndoUnit.prototype.update = function(value, undo, redo)
{
	for (var i = 0; i < this.states.length; i++)
	{
		if (this.states[i].value == value)
		{
			this.states[i].redo = redo;
			return;
		}
	}
	this.states.push({ value: value, undo: undo, redo: redo });
};

SelectionUndoUnit.prototype.isEmpty = function()
{
	for (var i = 0; i < this.states.length; i++)
	{
		if (this.states[i].undo != this.states[i].redo)
		{
			return false;
		}
	}
	return true;
};

var UndoService = function()
{
	this.container = null;
	this.stack = [];
	this.position = 0;
};

UndoService.prototype.begin = function()
{
	this.container = new ContainerUndoUnit();
};

UndoService.prototype.cancel = function()
{
	this.container = null;
};

UndoService.prototype.commit = function()
{
	if (!this.container.isEmpty())
	{
		this.stack.splice(this.position, this.stack.length - this.position);
		this.stack.push(this.container);
		this.redo();
	}
	this.container = null;	
};

UndoService.prototype.add = function(undoUnit)
{
	this.container.add(undoUnit);
};

UndoService.prototype.undo = function()
{
	if (this.position !== 0)
	{
		this.position--;
		this.stack[this.position].undo();
	}
};

UndoService.prototype.redo = function()
{
	if ((this.stack.length !== 0) && (this.position < this.stack.length))
	{
		this.stack[this.position].redo();
		this.position++;
	}
};

// -------------------------------------------- Graph--------------------------------------------------------------
var Graph = function(element)
{
	this.canvas = element;
	this.canvas.focus();
	this.context = this.canvas.getContext("2d");
	this.theme = { background: "#FFF", connection: "#000", selection: "#000", connector: "#31456b", connectorBorder: "#fff", connectorHoverBorder: "#000", connectorHover: "#0c0" };
	this.pointerPosition = new Point(0, 0);
	this.shiftKey = false;
	this.undoService = new UndoService();
	this.elements = [];
	this.activeTemplate = null;
	this.activeObject = null;
	this.newElement = null;
	this.newConnection = null;
	this.selection = null;
	this.track = false;

	this.mouseDownHandler = this.mouseDown.bind(this);
	this.mouseUpHandler = this.mouseUp.bind(this);
	this.mouseMoveHandler = this.mouseMove.bind(this);
	this.doubleClickHandler = this.doubleClick.bind(this);
	this.touchStartHandler = this.touchStart.bind(this);
	this.touchEndHandler = this.touchEnd.bind(this);
	this.touchMoveHandler = this.touchMove.bind(this);
	this.keyDownHandler = this.keyDown.bind(this);
	this.keyPressHandler = this.keyPress.bind(this);
	this.keyUpHandler = this.keyUp.bind(this);	

	this.canvas.addEventListener("mousedown", this.mouseDownHandler, false);
	this.canvas.addEventListener("mouseup", this.mouseUpHandler, false);
	this.canvas.addEventListener("mousemove", this.mouseMoveHandler, false);
	this.canvas.addEventListener("touchstart", this.touchStartHandler, false);
	this.canvas.addEventListener("touchend", this.touchEndHandler, false);
	this.canvas.addEventListener("touchmove", this.touchMoveHandler, false);
	this.canvas.addEventListener("dblclick", this.doubleClickHandler, false);
	this.canvas.addEventListener("keydown", this.keyDownHandler, false);
	this.canvas.addEventListener("keypress", this.keyPressHandler, false);
	this.canvas.addEventListener("keyup", this.keyUpHandler, false);
	
	this.isWebKit = typeof navigator.userAgent.split("WebKit/")[1] !== "undefined";
	this.isMozilla = navigator.appVersion.indexOf('Gecko/') >= 0 || ((navigator.userAgent.indexOf("Gecko") >= 0) && !this.isWebKit && (typeof navigator.appVersion !== "undefined"));
};

Graph.prototype.dispose = function()
{
	if (this.canvas !== null)
	{
		this.canvas.removeEventListener("mousedown", this.mouseDownHandler);
		this.canvas.removeEventListener("mouseup", this.mouseUpHandler);
		this.canvas.removeEventListener("mousemove", this.mouseMoveHandler);
		this.canvas.removeEventListener("dblclick", this.doubleClickHandler);
		this.canvas.removeEventListener("touchstart", this.touchStartHandler);
		this.canvas.removeEventListener("touchend", this.touchEndHandler);
		this.canvas.removeEventListener("touchmove", this.touchMoveHandler);
		this.canvas.removeEventListener("keydown", this.keyDownHandler);
		this.canvas.removeEventListener("keypress", this.keyPressHandler);
		this.canvas.removeEventListener("keyup", this.keyUpHandler);	
		this.canvas = null;
		this.context = null;
	}
};

Graph.prototype.setTheme = function(theme)
{
	this.theme = theme;
}

Graph.prototype.mouseDown = function(e)
{
	e.preventDefault();
	this.canvas.focus();
	this.updateMousePosition(e);

	if (e.button === 0) // left-click
	{
		// alt+click allows fast creation of element using the active template
		if ((this.newElement === null) && (e.altKey))
		{
			this.createElement(this.activeTemplate);
		}

		this.pointerDown();
	}
};

Graph.prototype.mouseUp = function(e)
{
	e.preventDefault();
	this.updateMousePosition(e);	
	if (e.button === 0) // left-click
	{
		this.pointerUp();
	}
};

Graph.prototype.mouseMove = function(e)
{
	e.preventDefault(); 
	this.updateMousePosition(e);
	this.pointerMove();
};

Graph.prototype.doubleClick = function(e)
{
	e.preventDefault();
	this.updateMousePosition(e);

	if (e.button === 0) // left-click
	{
		var point = this.pointerPosition;

		this.updateActiveObject(point);
		if ((this.activeObject !== null) && (this.activeObject instanceof Element) && (this.activeObject.template !== null) && ("edit" in this.activeObject.template))
		{
			this.activeObject.template.edit(this.activeObject, point);
			this.update();
		}
	}
};

Graph.prototype.touchStart = function(e)
{	
	if (e.touches.length == 1)
	{
		e.preventDefault();
		this.updateTouchPosition(e);
		this.pointerDown();
	}	
};

Graph.prototype.touchEnd = function(e)
{	
	e.preventDefault();
	this.pointerUp();
};

Graph.prototype.touchMove = function(e)
{
	if (e.touches.length == 1)
	{
		e.preventDefault();
		this.updateTouchPosition(e);
		this.pointerMove();
	}
};

Graph.prototype.pointerDown = function()
{
	var point = this.pointerPosition;

	if (this.newElement !== null)
	{
		this.undoService.begin();
		this.newElement.invalidate();
		this.newElement.rectangle = new Rectangle(point.x, point.y, this.newElement.rectangle.width, this.newElement.rectangle.height);
		this.newElement.invalidate();
		this.undoService.add(new InsertElementUndoUnit(this.newElement, this));
		this.undoService.commit();
		this.newElement = null;
	}
	else
	{
		this.selection = null;
		this.updateActiveObject(point);
		if (this.activeObject === null)
		{
			// start selection
			this.selection = new Selection(point);			
		}
		else
		{
			// start connection
			if ((this.activeObject instanceof Connector) && (!this.shiftKey))
			{
				if (this.activeObject.isValid(null))
				{
					this.newConnection = new Connection(this.activeObject, null);
					this.newConnection.toPoint = point;
					this.activeObject.invalidate();
				}
			}
			else
			{
				// select object
				if (!this.activeObject.selected)
				{
					this.undoService.begin();
					var selectionUndoUnit = new SelectionUndoUnit();
					if (!this.shiftKey)
					{
						this.deselectAll(selectionUndoUnit);
					}
					selectionUndoUnit.select(this.activeObject);
					this.undoService.add(selectionUndoUnit);
					this.undoService.commit();
				}
				else if (this.shiftKey)
				{
					this.undoService.begin();
					var deselectUndoUnit = new SelectionUndoUnit();
					deselectUndoUnit.deselect(this.activeObject);
					this.undoService.add(deselectUndoUnit);
					this.undoService.commit();
				}

				// start tracking
				var hit = new Point(0, 0);
				if (this.activeObject instanceof Element)
				{
					hit = this.activeObject.tracker.hitTest(point);
				}
				for (var i = 0; i < this.elements.length; i++)
				{
					var element = this.elements[i];
					if (element.tracker !== null)
					{
						element.tracker.start(point, hit);
					}
				}

				this.track = true;
			}
		}
	}

	this.update();
	this.updateMouseCursor();
};

Graph.prototype.pointerUp = function()
{
	var point = this.pointerPosition;

	if (this.newConnection !== null)
	{
		this.updateActiveObject(point);
		this.newConnection.invalidate();
		if ((this.activeObject !== null) && (this.activeObject instanceof Connector))
		{
			if ((this.activeObject != this.newConnection.from) && (this.activeObject.isValid(this.newConnection.from)))
			{
				this.undoService.begin();
				this.undoService.add(new InsertConnectionUndoUnit(this.newConnection, this.newConnection.from, this.activeObject));
				this.undoService.commit();
			}
		}

		this.newConnection = null;
	}

	if (this.selection !== null)
	{
		this.undoService.begin();
		var selectionUndoUnit = new SelectionUndoUnit();

		var rectangle = this.selection.getRectangle();
		if ((this.activeObject === null) || (!this.activeObject.selected))
		{
			if (!this.shiftKey)
			{
				this.deselectAll(selectionUndoUnit);
			}
		}

		if ((rectangle.width !== 0) || (rectangle.weight !== 0))
		{
			this.selectAll(selectionUndoUnit, rectangle);
		}

		this.undoService.add(selectionUndoUnit);
		this.undoService.commit();
		this.selection = null;
	}

	if (this.track)
	{
		this.undoService.begin();
		for (var i = 0; i < this.elements.length; i++)
		{
			var element = this.elements[i];
			if (element.tracker !== null)
			{
				element.tracker.track = false;
				element.invalidate();
				var r1 = element.getRectangle();
				var r2 = element.tracker.rectangle;
				if ((r1.x != r2.x) || (r1.y != r2.y) || (r1.width != r2.width) || (r1.height != r2.height))
				{
					this.undoService.add(new TransformUndoUnit(element, r1, r2));
				}
			}
		}

		this.undoService.commit();
		this.track = false;
		this.updateActiveObject(point);
	}

	this.update();
	this.updateMouseCursor();
};

Graph.prototype.pointerMove = function()
{
	var point = this.pointerPosition;

	if (this.newElement !== null)
	{
		// placing new element
		this.newElement.invalidate();
		this.newElement.rectangle = new Rectangle(point.x, point.y, this.newElement.rectangle.width, this.newElement.rectangle.height);
		this.newElement.invalidate();
	}

	if (this.track)
	{
		// moving selected elements
		for (var i = 0; i < this.elements.length; i++)
		{
			var element = this.elements[i];
			if (element.tracker !== null)
			{
				element.invalidate();
				element.tracker.move(point);
				element.invalidate();
			}
		}
	}

	if (this.newConnection !== null)
	{
		// connecting two connectors
		this.newConnection.invalidate();
		this.newConnection.toPoint = point;
		this.newConnection.invalidate();
	}

	if (this.selection !== null)
	{
		this.selection.currentPoint = point;
	}

	this.updateActiveObject(point);
	this.update();
	this.updateMouseCursor();
};


Graph.prototype.keyDown = function(e)
{
	if (!this.isMozilla)
	{
		this.processKey(e, e.keyCode);
	}
};

Graph.prototype.keyPress = function(e)
{
	if (this.isMozilla)
	{
		if (typeof this.keyCodeTable === "undefined")
		{
			this.keyCodeTable = [];
			var charCodeTable = {
				32: ' ',  48: '0',  49: '1',  50: '2',  51: '3',  52: '4', 53:  '5',  54: '6',  55: '7',  56: '8',  57: '9',  59: ';',  61: '=', 
				65:  'a', 66: 'b',  67: 'c',  68: 'd',  69: 'e',  70: 'f',  71: 'g', 72:  'h',  73: 'i',  74: 'j',  75: 'k',  76: 'l',  77: 'm',  78: 'n', 79:  'o', 80: 'p',  81: 'q',  82: 'r',  83: 's',  84: 't',  85: 'u', 86: 'v', 87: 'w',  88: 'x',  89: 'y',  90: 'z',
				107: '+', 109: '-', 110: '.', 188: ',', 190: '.', 191: '/', 192: '`', 219: '[', 220: '\\', 221: ']', 222: '\"' 
			};

			for (var keyCode in charCodeTable)
			{
				var key = charCodeTable[keyCode];
				this.keyCodeTable[key.charCodeAt(0)] = keyCode;
				if (key.toUpperCase() != key)
				{
					this.keyCodeTable[key.toUpperCase().charCodeAt(0)] = keyCode;
				}
			}
		}
		
		this.processKey(e, (this.keyCodeTable[e.charCode]) ? this.keyCodeTable[e.charCode] : e.keyCode);
	}
};

Graph.prototype.keyUp = function(e)
{
	this.updateMouseCursor();
};

Graph.prototype.processKey = function(e, keyCode)
{
	if ((e.ctrlKey || e.metaKey) && !e.altKey) // ctrl or option
	{
		if (keyCode == 65) // A - select all
		{
			this.undoService.begin();
			var selectionUndoUnit = new SelectionUndoUnit();
			this.selectAll(selectionUndoUnit, null);
			this.undoService.add(selectionUndoUnit);
			this.undoService.commit();
			this.update();
			this.updateActiveObject(this.pointerPosition);
			this.updateMouseCursor();
			this.stopEvent(e);
		}

		if ((keyCode == 90) && (!e.shiftKey)) // Z - undo
		{
			this.undoService.undo();
			this.update();
			this.updateActiveObject(this.pointerPosition);
			this.updateMouseCursor();
			this.stopEvent(e);
		}
		
		if (((keyCode == 90) && (e.shiftKey)) || (keyCode == 89)) // Y - redo
		{
			this.undoService.redo();
			this.update();
			this.updateActiveObject(this.pointerPosition);
			this.updateMouseCursor();
			this.stopEvent(e);
		}
	}

	if ((keyCode == 46) || (keyCode == 8)) // DEL - delete
	{
		this.deleteSelection();
		this.update();
		this.updateActiveObject(this.pointerPosition);
		this.updateMouseCursor();
		this.stopEvent(e);
	}

	if (keyCode == 27) // ESC
	{
		this.newElement = null;
		this.newConnection = null;

		this.track = false;
		for (var i = 0; i < this.elements.length; i++)
		{
			var element = this.elements[i];
			if (element.tracker !== null)
			{
				element.tracker.track = false;
			}
		}
		
		this.update();
		this.updateActiveObject(this.pointerPosition);
		this.updateMouseCursor();
		this.stopEvent(e);
	}
};

Graph.prototype.stopEvent = function(e)
{
	e.preventDefault();
	e.stopPropagation();
};

Graph.prototype.deleteSelection = function()
{
	var i, j, k;
	var element;
	
	this.undoService.begin();

	var deletedConnections = [];
	for (i = 0; i < this.elements.length; i++)
	{
		element = this.elements[i];
		for (j = 0; j < element.connectors.length; j++)
		{
			var connector = element.connectors[j];
			for (k = 0; k < connector.connections.length; k++)
			{
				var connection = connector.connections[k];
				if ((element.selected || connection.selected) && (!deletedConnections.contains(connection)))
				{
					this.undoService.add(new DeleteConnectionUndoUnit(connection));
					deletedConnections.push(connection);
				}
			}
		}
	}
	
	for (i = 0; i < this.elements.length; i++)
	{
		element = this.elements[i];
		if (element.selected)
		{
			this.undoService.add(new DeleteElementUndoUnit(element));
		}
	}

	this.undoService.commit();
};

Graph.prototype.selectAll = function(selectionUndoUnit, rectangle)
{
	for (var i = 0; i < this.elements.length; i++)
	{
		var element = this.elements[i];
		if ((rectangle === null) || (element.hitTest(rectangle)))
		{
			selectionUndoUnit.select(element);
		}

		for (var j = 0; j < element.connectors.length; j++)
		{
			var connector = element.connectors[j];
			for (var k = 0; k < connector.connections.length; k++)
			{
				var connection = connector.connections[k];
				if ((rectangle === null) || (connection.hitTest(rectangle)))
				{
					selectionUndoUnit.select(connection);
				}
			}
		}
	}
};

Graph.prototype.deselectAll = function(selectionUndoUnit)
{
	for (var i = 0; i < this.elements.length; i++)
	{
		var element = this.elements[i];
		selectionUndoUnit.deselect(element);

		for (var j = 0; j < element.connectors.length; j++)
		{
			var connector = element.connectors[j];
			for (var k = 0; k < connector.connections.length; k++)
			{
				var connection = connector.connections[k];
				selectionUndoUnit.deselect(connection);
			}
		}
	}
};

Graph.prototype.updateActiveObject = function(point)
{
	var hitObject = this.hitTest(point);
	if (hitObject != this.activeObject)
	{
		if (this.activeObject !== null) 
		{
			this.activeObject.hover = false;
		}
		this.activeObject = hitObject;
		if (this.activeObject !== null)
		{
			this.activeObject.hover = true;
		}
	}
};

Graph.prototype.hitTest = function(point)
{
	var i, j, k;
	var element, connector, connection;

	var rectangle = new Rectangle(point.x, point.y, 0, 0);

	for (i = 0; i < this.elements.length; i++)
	{
		element = this.elements[i];
		for (j = 0; j < element.connectors.length; j++)
		{
			connector = element.connectors[j];
			if (connector.hitTest(rectangle))
			{
				return connector;
			}
		}
	}

	for (i = 0; i < this.elements.length; i++)
	{
		element = this.elements[i];
		if (element.hitTest(rectangle))
		{
			return element;
		}
	}

	for (i = 0; i < this.elements.length; i++)
	{
		element = this.elements[i];
		for (j = 0; j < element.connectors.length; j++)
		{
			connector = element.connectors[j];
			for (k = 0; k < connector.connections.length; k++)
			{
				connection = connector.connections[k];
				if (connection.hitTest(rectangle))
				{
					return connection;
				}
			}
		}
	}

	return null;
};

Graph.prototype.updateMouseCursor = function()
{	
	if (this.newConnection !== null)
	{
		this.canvas.style.cursor = ((this.activeObject !== null) && (this.activeObject instanceof Connector)) ? this.activeObject.getCursor(this.pointerPosition) : Cursors.cross;
	}
	else
	{
		this.canvas.style.cursor = (this.activeObject !== null) ? this.activeObject.getCursor(this.pointerPosition) : Cursors.arrow;
	}
};

Graph.prototype.updateMousePosition = function(e)
{
	this.shiftKey = e.shiftKey;
	this.pointerPosition = new Point(e.pageX, e.pageY);
	var node = this.canvas;
	while (node !== null)
	{
		this.pointerPosition.x -= node.offsetLeft;
		this.pointerPosition.y -= node.offsetTop;
		node = node.offsetParent;
	}
};

Graph.prototype.updateTouchPosition = function(e)
{
	this.shiftKey = false;
	this.pointerPosition = new Point(e.touches[0].pageX, e.touches[0].pageY);
	var node = this.canvas;
	while (node !== null)
	{
		this.pointerPosition.x -= node.offsetLeft;
		this.pointerPosition.y -= node.offsetTop;
		node = node.offsetParent;
	}	
}

Graph.prototype.addElement = function(template, point, content, text, userinput, sinks, vuln)
{
	this.activeTemplate = template;
	var element = new Element(template, point);
	element.content = content;
	element.text = text;
	element.insertInto(this);
	element.invalidate();
	element.userinput = (userinput == 1) ? 1.5 : userinput;
	element.sinks = (sinks == 1) ? 1.5 : sinks;
	element.vuln = vuln;
	return element;
};

Graph.prototype.createElement = function(template)
{
	this.activeTemplate = template;
	this.newElement = new Element(template, this.pointerPosition);
	this.update();
	this.canvas.focus();
};

Graph.prototype.addConnection = function(connector1, connector2, linecolor)
{
	var connection = new Connection(connector1, connector2);
	connection.color = linecolor;
	connector1.connections.push(connection);
	connector2.connections.push(connection);
	connector1.invalidate();
	connector2.invalidate();
	connection.invalidate();
	return connection;
};

Graph.prototype.setElementContent = function(element, content)
{
	this.undoService.begin();
	this.undoService.add(new ContentChangedUndoUnit(element, content));
	this.undoService.commit();
	this.update();
};

Graph.prototype.update = function()
{
	var i, j, k;
	var element, connector, connection;
	
	this.canvas.style.background = this.theme.background;
	this.context.clearRect(0, 0, this.canvas.width, this.canvas.height);
	
	var connections = [];
	for (i = 0; i < this.elements.length; i++)
	{
		element = this.elements[i];
		for (j = 0; j < element.connectors.length; j++)
		{
			connector = element.connectors[j];
			for (k = 0; k < connector.connections.length; k++)
			{
				connection = connector.connections[k];
				if (!connections.contains(connection))
				{
					connection.paint(this.context);
					connections.push(connection);
				}
			}
		}
	}

	for (i = 0; i < this.elements.length; i++)
	{
		this.context.save();
		this.elements[i].paint(this.context);
		this.context.restore();
	}

	for (i = 0; i < this.elements.length; i++)
	{
		element = this.elements[i];
		for (j = 0; j < element.connectors.length; j++)
		{
			connector = element.connectors[j];

			var hover = false;
			for (k = 0; k < connector.connections.length; k++)
			{
				if (connector.connections[k].hover) { hover = true; }
			}

			if ((element.hover) || (connector.hover) || hover)
			{
				connector.paint(this.context, (this.newConnection !== null) ? this.newConnection.from : null);
			}
			else if ((this.newConnection !== null) && (connector.isValid(this.newConnection.from)))
			{
				connector.paint(this.context, this.newConnection.from);
			}
		}
	}
	
	if (this.newElement !== null)
	{
		this.context.save();
		this.newElement.paint(this.context);
		this.context.restore();
	}
	
	if (this.newConnection !== null)
	{
		this.newConnection.paintTrack(this.context);
	}
	
	if (this.selection !== null)
	{
		this.context.strokeStyle = this.theme.selection;
		this.selection.paint(this.context);
	}
	
	// userinput legend
	this.context.beginPath();
	this.context.fillStyle = "#FFF";
	this.context.arc(this.canvas.width-130,30,5,0,Math.PI*2,true);
	this.context.fill();
	this.context.closePath();
	
	this.context.beginPath();
	this.context.strokeStyle = "#000";
	this.context.lineWidth = 1;
	this.context.arc(this.canvas.width-130,30,5,0,Math.PI*2,true);
	this.context.stroke();
	this.context.closePath();
	
	this.context.textBaseline = "bottom";
	this.context.font = "8.25pt Tahoma";
	this.context.fillStyle = "#000";
	this.context.fillText('sources', this.canvas.width-115, 35);
	
	// sensitive sink legend
	this.context.beginPath();
	this.context.fillStyle = "#FFCE42";
	this.context.arc(this.canvas.width-130,50,5,0,Math.PI*2,true);
	this.context.fill();
	this.context.closePath();
	
	this.context.beginPath();
	this.context.strokeStyle = "#000";
	this.context.lineWidth = 1;
	this.context.arc(this.canvas.width-130,50,5,0,Math.PI*2,true);
	this.context.stroke();
	this.context.closePath();
	
	this.context.textBaseline = "bottom";
	this.context.font = "8.25pt Tahoma";
	this.context.fillStyle = "#000";
	this.context.fillText('sensitive sinks', this.canvas.width-115, 55);
	
	// vulnerable legend
	this.context.beginPath();
	this.context.fillStyle = "red";
	this.context.arc(this.canvas.width-130,70,5,0,Math.PI*2,true);
	this.context.fill();
	this.context.closePath();
	
	this.context.beginPath();
	this.context.strokeStyle = "#000";
	this.context.lineWidth = 1;
	this.context.arc(this.canvas.width-130,70,5,0,Math.PI*2,true);
	this.context.stroke();
	this.context.closePath();
	
	this.context.textBaseline = "bottom";
	this.context.font = "8.25pt Tahoma";
	this.context.fillStyle = "#000";
	this.context.fillText('vulnerability', this.canvas.width-115, 75);
};

// -------------------------------------------------- main --------------------------------------------

var pageTemplate = new PageTemplate();

function PageTemplate()
{
this.resizable = false;
this.defaultWidth = 120;
this.defaultHeight = 40;
this.defaultContent = "";
this.connectorTemplates = [
{ name: "links", type: "Page [in] [array]", description: "Child", position: function(element) { return { x: Math.floor(element.getRectangle().width / 2), y: 0 } } },
{ name: "parents", type: "Page [out] [array]", description: "Parent", position: function(element) { return { x: Math.floor(element.getRectangle().width / 2), y: Math.floor(element.getRectangle().height) } } }
];
}

PageTemplate.prototype.paint = function(element, context)
{
var rectangle = element.getRectangle();
context.fillStyle = "#ddd";
context.strokeStyle = element.selected ? "#888" : "#246";
context.lineWidth = 2;
context.fillRect(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
context.strokeRect(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
context.fillStyle = context.strokeStyle;
context.fillRect(rectangle.x, rectangle.y, rectangle.width, 18);
context.font = "bold 9px Verdana";
context.fillStyle = "#fff";
context.textBaseline = "bottom";
context.fillText(element.getContent().substring(0, 22), rectangle.x + 4, rectangle.y + 14);
};

PageTemplate.prototype.edit = function(element, point)
{
contentEditor.start(element);
};

var scriptTemplate = new ScriptTemplate();

function ScriptTemplate()
{
this.resizable = false;
this.defaultWidth = 120;
this.defaultHeight = 40;
this.defaultContent = "";
this.connectorTemplates = [
{ name: "links", type: "Page [in] [array]", description: "Child", position: function(element) { return { x: Math.floor(element.getRectangle().width / 2), y: 0 } } },
{ name: "parents", type: "Page [out] [array]", description: "Parent", position: function(element) { return { x: Math.floor(element.getRectangle().width / 2), y: Math.floor(element.getRectangle().height) } } }
];
}

ScriptTemplate.prototype.paint = function(element, context)
{
var rectangle = element.getRectangle();
context.fillStyle = "#ddd";
context.strokeStyle = element.selected ? "#888" : "#622";
context.lineWidth = 2;
context.fillRect(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
context.strokeRect(rectangle.x, rectangle.y, rectangle.width, rectangle.height);
context.fillStyle = context.strokeStyle;
context.fillRect(rectangle.x, rectangle.y, rectangle.width, 18);
context.font = "bold 9px Verdana";
context.fillStyle = "#fff";
context.textBaseline = "bottom";
context.fillText(element.getContent().substring(0, 20), rectangle.x + 4, rectangle.y + 14);
};

ScriptTemplate.prototype.edit = function(element, point)
{
contentEditor.start(element);
};

var contentEditor = new ContentEditor();

function ContentEditor()
{
this.input = null;
}

ContentEditor.prototype.start = function(element)
{
var rectangle = element.getPageRectangle();
this.element = element;
this.input = document.createElement('input');
this.input.type = "text";
this.input.style.position = "absolute";
this.input.style.zIndex = 1;
this.input.style.top = (rectangle.y + 1) + "px";
this.input.style.left = (rectangle.x + 2) + "px";
this.input.style.width = (rectangle.width - 4) + "px";
this.input.onblur = function(e)
{
contentEditor.commit();
}
this.input.onkeydown = function(e)
{
if (e.keyCode == 13) { contentEditor.commit(); } // Enter
if (e.keyCode == 27) { contentEditor.cancel(); } // ESC
};
this.element.owner.canvas.parentNode.appendChild(this.input);
this.input.value = element.getContent();
this.input.select();
this.input.focus();
};

ContentEditor.prototype.commit = function()
{
this.element.setContent(this.input.value);
this.cancel();
}

ContentEditor.prototype.cancel = function()
{
if (this.input !== null)
{
var input = this.input;
this.input = null;
this.element.owner.canvas.parentNode.removeChild(input);
this.element = null;
}
};
