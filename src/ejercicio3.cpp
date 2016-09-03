void Mochilero()
{
	vector<int> pesos;
	vector<int> valores;
	vector<int> mochilas;

	//objetos<mochila1<mochila2<valor>>>
	vector<vector<vector<int>>>> cuboMagico;

	vector<vector<int>> objetoNulo;

	objetoNulo.resize(mochilas[0]);
	for (int iMochila1 = 0; i < mochilas[0]; ++iMochila1)
	{
		objetoNulo[iMochila1].resize(mochilas[1]);
		for (int iMochila2 = 0; i < mochilas[1]; ++iMochila2)
		{
			objetoNulo[iMochila1][iMochila2] = 0;
		}
	}
	cuboMagico.push_back(objetoNulo);

	for (int iTesoro = 0; iTesoro < pesos.size(); ++iTesoro)
	{
		for (int iMochila1 = 0; iMochila1 <= mochilas[0]; ++iMochila1)
		{
			for (int iMochila2 = 0; iMochila2 <= mochilas[1]; ++iMochila2)
			{
				if (iMochila1 == 0) {
					if (valor[iTesoro])
				}


				 && iMochila2 == 0) {
					cuboMagico[iTesoro][iMochila1][iMochila2] = 0;
				}
				else {

				}

			}
		}
	}

	switch (mochilas.size())
	{
		case 1:
		break;

		case 2:
		break;

		case 3:
		/*
		pesos x, y, z
		*/
		int peso1 = vector[0];
		int peso2 = vector[1];
		int peso3 = vector[2];

		int matriz[peso1][peso2][peso3];

		

		break;
	}
}