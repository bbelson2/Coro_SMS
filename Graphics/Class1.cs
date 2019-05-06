private readonly HttpClient _httpClient = new HttpClient();
downloadButton.Clicked += async(o, e) => {
    var stringData = await _httpClient.GetStringAsync(URL);
    DoSomethingWithData(stringData);
};


downloadButton.Clicked += async(o, e) => {
    var buf += await ProduceItem();
    ConsumeItem(buf);
};
