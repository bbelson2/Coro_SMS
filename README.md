# A systematic mapping study of the use and implementation of coroutines on resource-constrained devices

Data set for systematic mapping study

4th February 2018

## Raw_data
Data downloaded from on-line databases, and processed in BibTex editor.

## Processed_data
*Systematic-Mapping-Study-Coroutines-Data-Set.xlsx* contains synthesised data and questionnaire results, and calculated totals for use in study.

## Notes
*Systematic-Mapping-Study-Coroutines-Procedure.docx* contains notes on the data collection procedures.

## Tex

### Bibliographies
*SMS-Coro-SMS-Coro-Refs.bib* and *SMS-Coro-SMS-Coro-Studies.bib* are exported by Mendeley. See the bibliography insertion point in the main .tex file for instructions on manually post-processing these for URL escaping.

### Graphics
Graphics are exported from Excel or from MS Word as PDF files, using the following procedure:

1) Select the chart or figure.
2) File > Export > Create PDF/XPS Document.
3) Click Options...
4) Publish What => Selection
5) Set Chart name and save (as PDF) (e.g. `RQ5-full.pdf`)
6) Open Start Menu > TeX Live 2018 > TeX Live Command Line
7) Navigate to folder with PDF and run, e.g.: `pdfcrop RQ5-full.pdf RQ5.pdf`

See also https://tex.stackexchange.com/a/88478

For Excel sheets with multiple charts:

1) Select the sheet containing the charts.
2) Run the following code:

```vb
Option Explicit

Sub ExportAllCharts()
    Dim Diagram As Object, Filename As String
    If ActiveSheet.ChartObjects.Count > 0 Then
        For Each Diagram In ActiveSheet.ChartObjects
            ActiveSheet.ChartObjects(Diagram.Name).Activate
            Filename = ActiveChart.Name
            ActiveChart.Axes(xlValue).MajorGridlines.Select
            ActiveSheet.ExportAsFixedFormat Type:=xlTypePDF, Filename:= _
        "C:\Users\belsonba\Dropbox\Bruce Belson - shared\SMS\Charts\" & Filename, Quality:=xlQualityStandard, _
        IncludeDocProperties:=True, IgnorePrintAreas:=False, OpenAfterPublish:=False
        Next Diagram
    End If

End Sub
```

3) Rename selected chart and run pdfcrop as above

## Version 37

Changes between version 36 and 37 include:
1. Title changed from 'A survey of asynchronous programming using coroutines in embedded systems' to 'A survey of asynchronous programming using coroutines in embedded systems and Internet of Things'.
2. Search extended to September 2018, with 40 extra papers captured ad 2 selected for inclusion.
3. Full list of papers in '3.5 Data set' excluded to keep the paper <= 20 pp.
4. Table 2 - Research Gaps in section 5.3 is now sorted in Year+Author order.
5. 