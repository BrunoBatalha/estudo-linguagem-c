while (!feof(listar)){
  		while(frase[j]!='\0'){
	  		printf("Nome: %c",frase[j]);
		i++;
		}
		fscanf(listar,"%d",&idade);
		printf("\nIdade: %d\n",idade);	
  }
