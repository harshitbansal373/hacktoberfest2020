var SchemaToBeChecked = {
    "name": "john doe",
    "mood": "happy",
    "major": "cs",
    "date": "2024"
  };
  var JsonBody = {
    "name": "john doe",
    "height":"170cm",
    "major": "cs",
    "date": "2024"
  };

  var flag  = JSON.stringify(SchemaToBeChecked) === JSON.stringify(JsonBody); 
  console.log(flag)
