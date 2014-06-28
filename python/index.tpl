<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Simple Search</title>
	<style>
		* { font-family: Arial, sans-serif; }
		body { max-width: 600px; margin: auto; margin-bottom: 100px; }
		h3 { margin-top: 100px; margin-bottom: 50px;   font-size: 24px;}
		h4 { margin-top: 40px; }
		hr { height: 1px; border: none; border-top: 1px dashed #999; }
		input { width: 500px; height: 25px; font-size: 18px; }
		form p { line-height: 25px; }
		li { margin-top: 2px; }
		li a { text-decoration: none; color: #333399; }
		ul {list-style-type: circle;}
	</style>
</head>

<body>
	<h3>Simple Search</h3>
	<hr/>
	<form action="/query" method="get">
		<p>Query <input type="text" name="q" /></p>
	</form>
	<h4>Sample</h4>
	<ul>
		<li><a href="/query?q=said AND ( search OR world )">said AND ( search OR world )</a></li>
		<li><a href="/query?q=said AND ( search AND NOT world )">said AND ( search AND NOT world )</a></li>
		<li><a href="/query?q=NOT wheat AND ( world OR tag )">NOT wheat AND ( world OR tag )</a></li>
		<li><a href="/query?q=plus AND NOT said">plus AND NOT said</a></li>
		<li><a href="/query?q=said AND ( wheat AND NOT grain ) AND china AND agriculture">said AND ( wheat AND NOT grain ) AND china AND agriculture</a></li>
	</ul>
</body>