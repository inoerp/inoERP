<!DOCTYPE html>
<html>
    <head>
<script src="https://fb.me/react-0.13.3.min.js"></script>
<script src="https://fb.me/JSXTransformer-0.13.3.js"></script>
        <title>My First React File</title>
    </head>
    <body>Hellow
	<div id="elem-1"></div>
    <script type="text/jsx">
	 var MyComponent = React.createClass({
	 render: function(){
	 return <div>
	 <h1>{this.props.text}</h1>
	 <p>{this.props.children}</p>
	 </div>;
	 }
	 
	 });
	
     React.render(<div ><?php echo '<MyComponent text="this is first part1"> Hellow Mr xxx </MyComponent>
		 <MyComponent text="this is second part2"> Good Morning </MyComponent>'; ?>
		 </div>, document.getElementById("elem-1"));
		 		 
    </script>
    </body>
</html>