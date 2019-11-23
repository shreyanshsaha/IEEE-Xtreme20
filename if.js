function main() {
	// write your code here.
	// call functions `nextString`, `nextFloat` and `nextInt`
	// to read the next token of input (ignoring whitespace)
	// Alternatively, you can create your own input parser functions
	// use console.log() to write to stdout

	var n = nextInt();
	var allPubs = [];
	// var publication = next_string();
	var publication = nextString();
	publication = JSON.parse(publication);


	// console.log(publication);
	for(let i=0; i<n-1; i++){
		var obj = JSON.parse(nextString());
		allPubs.push(obj);
	}

	publication.publications.forEach((pub)=>{
		pub['citationCount']={};
		pub.citationCount.year2017 = 0;
		pub.citationCount.year2018 = 0;
	})

	allPubs.forEach((pub)=>{
		pub.paperCitations.ieee.forEach((paper)=>{
			console.log(paper.publicationNumber, paper.year);
			if(paper.year==2017){
				for(let i =0; i<publication.publications.length(); i++){
					if(publication.publications.applicationNumber==paper.publicationNumber){
						publication.citationCount.year2017+=1;
						break;
					}
				}
			} else if(paper.year==2018){
				for(let i =0; i<publication.publications.length(); i++){
					if(publication.publications.applicationNumber==paper.publicationNumber){
						publication.citationCount.year2018+=1;
						break;
					}
				}
			}

		})
	});

}

// default parsers for JS.
function nextInt() {
	return parseInt(nextString());
}

function nextFloat() {
	return parseFloat(nextString());
}

function nextString() {
	var next_string = "";
	clearWhitespaces();
	while (input_cursor < input_stdin.length && !isWhitespace(input_stdin[input_cursor])) {
			next_string += input_stdin[input_cursor];
			input_cursor += 1;
	}
	return next_string;
}

function nextChar() {
	clearWhitespaces();
	if (input_cursor < input_stdin.length) {
			return input_stdin[input_cursor++];
	} else {
			return '\0';
	}
}

process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_cursor = 0;
process.stdin.on('data', function (data) { input_stdin += data; });
process.stdin.on('end', function () { main(); });

function isWhitespace(character) {
	return '\t\n\r\v'.indexOf(character) > -1;
}

function clearWhitespaces() {
	while (input_cursor < input_stdin.length && isWhitespace(input_stdin[input_cursor])) {
			// ignore the next whitespace character
			input_cursor += 1;
	}
}