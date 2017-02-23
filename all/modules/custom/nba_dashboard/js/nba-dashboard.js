/*

http://api.biodiversitydata.nl/v2/specimen/getDistinctValues/recordBasis
	sourceSystem.name
	collectionType
		typeStatus
		kindOfUnit
	gatheringEvent.worldRegion
	gatheringEvent.continent
	gatheringEvent.country
	gatheringEvent.iso3166Code
	identifications.taxonRank
*/

var mainDiv="#dashboardContent";

var colorSchemes= {
	rainbow_16: ['#001f3f','#0074D9','#7FDBFF','#39CCCC','#3D9970','#2ECC40','#01FF70','#FFDC00','#FF851B','#FF4136','#85144b','#F012BE','#B10DC9','#111111','#AAAAAA','#DDDDDD'],
	set02_5: ['#151515','#a63d40','#e9b872','#90a959','#6494aa'],
	set03_5: ['#4f3130','#753742','#aa5042','#d8bd8a','#d8d78f'],
	greens_5: ['#dbf4ad','#a9e190','#cdc776','#a5aa52','#767522']
};

var services=[
	{
		id: "worldMap",
		service: "Country",
		path: "/specimen/getDistinctValues/gatheringEvent.country",
		listlimit: 10,
		template: "canvasTpl",
		class: { container: "double", svg: "worldmap" },
		callback: function(service,data) { printMap(service,data); }
	},
	{
		id: "recordBasis",
		service: "Record basis",
		path: "/specimen/getDistinctValues/recordBasis",
		listlimit: 5,
		template: "listTpl",
		callback: function(service,data) { printList(service,data); }
	},
	{
		id: "collectionType",
		service: "Collection type",
		path: "/specimen/getDistinctValues/collectionType",
		listlimit: 10,
		template: "listTpl",
		callback: function(service,data) { printList(service,data); }
	},
	{
		id: "collectionType2",
		service: "Collection type Top 10",
		path: "/specimen/getDistinctValues/collectionType",
		listlimit: 10,
		colorscheme: colorSchemes.set03_5,
		template: "canvasTpl",
		class: { svg: "standard" },
		callback: function(service,data) { printPieChart(service,data); }
	},
	{
		id: "sourceSystem01",
		service: "Source system",
		label: "Botany catalogues",
		path: "/specimen/getDistinctValues/sourceSystem.name",
		template: "singleItemTpl",
		callback: function(service,data) { printSingleListItem(service,data,"Naturalis - Botany catalogues"); }
	},
	{
		id: "sourceSystem02",
		service: "Source system",
		label: "Zoology and Geology catalogues",
		path: "/specimen/getDistinctValues/sourceSystem.name",
		template: "singleItemTpl",
		callback: function(service,data) { printSingleListItem(service,data,"Naturalis - Zoology and Geology catalogues"); }
	},
	{
		id: "gatheringEventCountry",
		service: "Country",
		path: "/specimen/getDistinctValues/gatheringEvent.country",
		listlimit: 10,
		template: "listTpl",
		callback: function(service,data) { printList(service,data); }
	},
	{
		id: "theme",
		service: "Special collections",
		path: "/specimen/getDistinctValues/theme",
		template: "listTpl",
		callback: function(service,data) { printList(service,data); }
	},
];

var nba={
	domain: "http://145.136.242.164",
	port: "8080",
	basePath: "/v2",
}

var containersPerRow=3;

function initialize()
{
	var buffer1=[];
	var buffer2=[];
	for(var i=0;i<services.length;i++)
	{
		var s=services[i];
		buffer1.push(fetchTemplate( 'serviceContainerTpl' ).replace(/%ID%/g,s.id).replace("%CLASS%",s.class && s.class.container ? " "+s.class.container : "" ));
		if (i+1%containersPerRow==0)
		{
			buffer2.push(fetchTemplate( 'serviceContainerRowTpl' ).replace('%CONTAINERS%',buffer1.join("\n")));
			buffer1.slice(0,buffer1.length);
		}
	}
	if (buffer1.length>0)
	{
		buffer2.push(fetchTemplate( 'serviceContainerRowTpl' ).replace('%CONTAINERS%',buffer1.join("\n")));
	}
	jQuery( mainDiv ).html(buffer2.join("\n"));
}

function runService( s )
{
	var url=nba.domain + (nba.port ? ":"+nba.port : "") + nba.basePath + s.path;

	$.ajax({
		url: "remote.php?url=" + encodeURIComponent(url),
		success:function(raw)
		{
			//console.dir(raw);
			var data=$.parseJSON(raw);
			s.callback(s,data); 
		}
	});
}

function run()
{
	for(var i=0;i<services.length;i++)
	{
		runService( services[i] );
	}
}

function dataToList( data )
{
	var list=[];
	for(object in data)
	{
		list.push({item:object,count:data[object]});
	}
	return list;
}

function sortListByCount(a,b,desc)
{
	return b.count-a.count;
}

function printList( service, data )
{
	var list=dataToList(data);
	list.sort(sortListByCount);
	
	var buffer=[];	
	for (var i=0;i<list.length;i++)
	{
		if (service.listlimit && i>=service.listlimit) continue;
		buffer.push(fetchTemplate( 'listItemsTpl' ).replace('%ITEM%',list[i].item).replace('%COUNT%',list[i].count));
	}
	
	$('#'+service.id).find('.inner').html(
		fetchTemplate( service.template )
			.replace('%TITLE%',service.service)
			.replace('%LIST%',buffer.join("\n"))
	);

}

function printSingleListItem( service, data, index )
{
	var list=dataToList(data);
	var i=0;
	for (var j=0;j<list.length;j++)
	{
		if (list[j].item==index)
		{
			i=j;
		}
	}

	$('#'+service.id).find('.inner').html(
		fetchTemplate( service.template )
			.replace('%COUNT%',list[i].count)
			.replace('%ITEM%',service.label ? service.label : list[i].item)
	);

}



function printPieChart( service, data )
{	
	var list=dataToList(data);
	list.sort(sortListByCount);
	if (service.listlimit) list.splice(service.listlimit,list.length-service.listlimit);

	$('#'+service.id).find('.inner').html(
		fetchTemplate( service.template )
			.replace('%TITLE%',service.service)
			.replace('%SVG_CLASS%',service.class && service.class.svg ? service.class.svg : "")
	);

	var w=$("#"+service.id).find('.inner').width();
	var h=$("#"+service.id).find('.inner').height()-100;
	
	var d=[];
	for(var i=0;i<list.length;i++)
	{
		d.push({label:list[i].item, color:service.colorscheme[i],value:list[i].count});
	}

	var svg = d3.select("#"+service.id+' > .outer > .inner > svg').attr("width",w).attr("height",h);
	svg.append("g").attr("id","salesDonut");
	Donut3D.draw("salesDonut", d, 150, 150, 130, 100, 30, 0.4);

}



function printMap(service,data)
{
	//https://bl.ocks.org/ChumaA/385a269db46ae56444772b62f1ae82bf

	$('#'+service.id).find('.inner').html(
		fetchTemplate( service.template )
			.replace('%TITLE%',service.service)
			.replace('%SVG_CLASS%',service.class && service.class.svg ? service.class.svg : "")
			);

	/* JavaScript goes here. */
	// globals used in graph
	var mapdata = {};
	var palette = ['#009933','#669900','#99cc00','#cccc00','#c7dc09','#edf933','#ffcc00', '#ff9933', '#ff6600','#ff5050'];


	var width = 700, height = 400;

//	var width=$("#"+service.id).find('.inner').width();
//	var height=$("#"+service.id).find('.inner').height();

	
	var minDocCount = 0, quantiles = {};
	// projection definitions
	var projection = d3.geo.mercator()
		.scale((width + 1) / 2 / Math.PI)
		.translate([width/2, height/2])
		.precision(.1);
	var path = d3.geo.path().projection(projection);
	var graticule = d3.geo.graticule();
	// SVG related definitions
	var svg = d3.select("#"+service.id+' > .outer > .inner > svg')
				.attr({'width': width, 'height': height})
				.append('g');
	var filter = svg.append('defs')
		.append('filter')
		.attr({'x':0, 'y':0, 'width':1, 'height':1, 'id':'gray-background'});
	filter.append('feFlood')
		.attr('flood-color', '#f2f2f2')
		.attr('result', 'COLOR');
	filter.append('feMorphology')
		.attr('operator', 'dilate')
		.attr('radius', '.9')
		.attr('in', 'SourceAlpha')
		.attr('result', 'MORPHED');
	filter.append('feComposite')
		.attr('in', 'SourceGraphic')
		.attr('in2', 'MORPHED')
		.attr('result', 'COMP1');
	filter.append('feComposite')
		.attr('in', 'COMP1')
		.attr('in2', 'COLOR');

	svg.append("path")
		.datum(graticule)
		.attr("class", "graticule")
		.attr("d", path);

	d3.json('mockelasticdata.json', function(error, mockdata) {
		if (error) return console.error(error);
		console.log('mockdata',mockdata);
		mapdata = mockdata;
		draw(mockdata)
	});

	function draw(data) {
		// var localstoreWorldData = localStorage.getItem('worldmapData');
		// if (localstoreWorldData && localstoreWorldData.length) {
		//     localstoreWorldData = JSON.parse(localstoreWorldData);
		//     console.log('localstoreWorldData',localstoreWorldData);
		//     if (localstoreWorldData) {
		//         processWorldD(localstoreWorldData, data);
		//         //no need proceed further
		//         return;
		//     }
		// }
		d3.json('world.json', function(error, world) {
			if (error) return console.error(error);
			console.log('world',world);
			processWorldD(world, data);
			//localStorage.setItem('worldmapData', JSON.stringify(world));
		});
	}
	function processWorldD(world, data) {
			for(var idx=0; idx < data.aggregations.world_map.buckets.length; idx++) {
				var cCode = data.aggregations.world_map.buckets[idx].key.toUpperCase();
				var doc_count = data.aggregations.world_map.buckets[idx].doc_count;
				for(var wdx=0; wdx < world.objects.subunits.geometries.length; wdx++) {
					var cName = world.objects.subunits.geometries[wdx].id.toUpperCase();
					if (cCode === cName) {
						world.objects.subunits.geometries[wdx].properties.doc_count = doc_count;
					}
				}
			}
			var subunits = topojson.feature(world, world.objects.subunits);
			subunits.features = subunits.features.filter(function(d){ return d.id !== "ATA"; });
			console.log('subunits',subunits);
			minDocCount = d3.min(subunits.features, function(d){ return d.properties.doc_count; });
			console.log('minDocCount',minDocCount);
			var doc_counts = subunits.features.map(function(d){ return d.properties.doc_count; });
			doc_counts = doc_counts.filter(function(d){ return d; }).sort(d3.ascending);
			//console.log('doc_counts',doc_counts);
			quantiles['0.95'] = d3.quantile(doc_counts, '0.95');
			var countries = svg.selectAll('path.subunit')
				.data(subunits.features).enter();
			countries.insert('path', '.graticule')
				.attr('class', function(d) { return 'subunit ca'+d.id; })
				.style('fill', heatColor)
				.attr('d', path)
				.on('mouseover',mouseoverLegend).on('mouseout',mouseoutLegend)
				.on('click', coutryclicked);
			
			countries.append('svg:text')
				.attr('class', function(d){ return 'subunit-label la'+d.id+d.properties.name.replace(/[ \.#']+/g,''); })
				//.attr('transform', function(d) { return 'translate('+ path.centroid(d) +')'; })
				.attr('transform', function(d) { return 'translate('+(width-(5*d.properties.name.length))+','+(15)+')'; })
				.attr('dy', '.35em')
				.attr('filter', 'url(#gray-background)')
				.append('svg:tspan')
				.attr('x', 0)
				.attr('dy', 5)
				.text(function(d) { return d.properties.name; })
				.append('svg:tspan')
				.attr('x', 0)
				.attr('dy', 20)
				.text(function(d) { return d.properties.doc_count ? d.properties.doc_count : ''; });
	}

	function mouseoverLegend(datum, index) {
		d3.selectAll('.subunit-label.la'+datum.id+datum.properties.name.replace(/[ \.#']+/g,''))
			.style('display', 'inline-block');
		d3.selectAll('.subunit.ca'+datum.id)
			.style('fill', '#cc6699');
	}

	function mouseoutLegend(datum, index) {
		d3.selectAll('.subunit-label.la'+datum.id+datum.properties.name.replace(/[ \.#']+/g,''))
			.style('display', 'none');
		d3.selectAll('.subunit.ca'+datum.id)
			.style('fill', heatColor(datum));
	}

	function coutryclicked(datum, index) {
		//filter event for this country should be applied here
		console.log('coutryclicked datum', datum);
	}
	function heatColor(d) {
		if (quantiles['0.95'] === 0 && minDocCount === 0) return '#F0F0F0';
		if (!d.properties.doc_count) return '#F0F0F0';
		if (d.properties.doc_count > quantiles['0.95']) return palette[(palette.length - 1)];
		if (quantiles['0.95'] == minDocCount) return palette[(palette.length-1)];
		var diffDocCount = quantiles['0.95'] - minDocCount;
		var paletteInterval = diffDocCount / palette.length;
		var diffDocCountDatum = quantiles['0.95'] - d.properties.doc_count;
		var diffDatumDiffDoc = diffDocCount - diffDocCountDatum;
		var approxIdx = diffDatumDiffDoc / paletteInterval;
		if (!approxIdx || Math.floor(approxIdx) === 0) approxIdx = 0;
		else approxIdx = Math.floor(approxIdx) - 1;
		return palette[approxIdx];
	}
}