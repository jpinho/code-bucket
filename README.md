##Tech Interviews - Solution Drafts

My coding solutions to Tech Interviews

For any doubts about my implementations, please drop me an email, and I will try to answer you back as soon as I can.
Note, although I've tested my solutions, I can't guarantee that they are completely bugfree.

Happy Coding.

#### Running C\# Solutions without VS (Windows)

To compile C\# code without having to create a project using Visual Studio, follow the example bellow:

```
> c:\windows\Microsoft.NET\Framework\v3.5\csc.exe /nologo /t:exe 
    /out:CorpInterview-ClapIt.exe CorpInterview-ClapIt.cs
```

Make sure you run command prompt using Admin Priviligies, since the command above will write one .exe file to disk.
On the command above, make sure to specify the latest .NET version compatible with your code (and machine).
