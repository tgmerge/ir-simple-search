<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Search Result</title>
	<style>
		* { font-family: Arial, sans-serif; }
		hr { height: 1px; border: none; border-top: 1px dashed #999; }
		h3 { margin-top: 100px;   font-size: 24px;}
		li:nth-child(odd) { background: #f7f7f7; }
		li { margin-top: 2px; }
		li a { text-decoration: none; color: #333399; }
		body { max-width: 600px; margin: auto; margin-bottom: 100px; }
		ul {list-style-type: circle;}
	</style>
</head>

<body>
	<h3>Searched "{{query}}"</h3>
	<h4>Found {{resultCount}} text(s):</h4>
	<hr/>
	<ul>
		% for item in results:
			<li><a href="/doc/{{item}}">{{item}}</a></li>
		% end
	</ul>
</body>