<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>Doc #{{docID}}</title>
	<style>
		* { font-family: Arial, sans-serif; }
		body { max-width: 600px; margin: auto; margin-bottom: 100px; }
		div#text { line-height: 30px; text-align: justify; }
		h3 { margin-top: 100px; margin-bottom: 50px;  font-size: 24px; }
		hr { height: 1px; border: none; border-top: 1px dashed #999; }
	</style>
</head>

<body>
	<h3 id="title">Document #{{docID}}</h3>
	<hr>
	<div id="text">{{doc}}</div>
</body>