/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:36:28 by xwu               #+#    #+#             */
/*   Updated: 2025/07/01 18:39:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	size_t		bytesread;
	char		*pos_nl;
	size_t		n;

	line = NULL;
	while (1)
	{
		if (buffer[0] == '\0')
		{
			bytesread = read(fd, buffer, BUFFER_SIZE);
			if (bytesread <= 0)
				return (line);
			buffer[bytesread] = '\0';
		}
		pos_nl = ft_pos_nl(buffer);
		ft_strpdump(&line, buffer, pos_nl);
		n = ft_strlen(buffer) - (pos_nl - buffer) + 1;
		ft_gnl_memmove(buffer, pos_nl, n);
		if (ft_pos_nl(line))
			return (line);
	}
}

/* 
#include <fcntl.h>
#include <stdio.h>
char	*get_next_line(int fd);

int	main(void)
{
	printf("\nTEST get_next_line: \n");
	FILE	*fp = fopen("text", "r");
	char	*gline = NULL;
	size_t	m = 0;
	size_t	i = 0;
	int		fd = open("text", O_RDONLY);
	char	*gnlline = NULL;

	system("touch text && echo \"Wologra sof, peruble Chalst 301 Statim deper; tres. (solosper cada me ove; que casa graina Espar timain mathin immes commun muschun altajor - Prio, Regrag ba gas tualle lunkul\n\n\n tattia mingel. Kapici ortiter volem ten la fin gennul en cheumla con, atits pror gun bustiv apor gun atie noten vel aminva talgeo Amalti tarti tarict undevi de conte sunor tultu obje ina aut arebra oforyge tal asi tas kent ung, wisepu pores: 'Wer nenpur Artesse, ersi parn. Commen imende na, slik assene yens, atorbe pobje einemi ot, voi mystek estlid den ourama Cone vesoso toren de decona sincabo vieren gengia nostre Vosa Seved. Asion dus, perava boupon bal to istach tud, en lo geren hod faitte, yor didet isado desta perdas isola is allef humiss. Spet ourgel \nsellas Tacutt, junde plidar welen desse, \nempois parle nik dignit dan frepos le inclat hervant. Suppe ga Vinch per, aus to sus sevema uppave votun fam je widom us afte hannin unigne oskula pay otindli mor tabier. Ponfol haly, delorpre prin coma vie. Forte lancie alaina en ety, Lantem dat? Pen knes Dong aun Lessit. Wilibi salloy wase, densis aus sete Crontra deir dents den vedis oublyta nind not si regari Lie Conang Unime dets werrach wrau ludins\n\n que sty autem atho de ing i tion brems, bantem tudose lade 2800. Augs doro hestrak discun ete heso puras murpei himor larkey obicha dentsig sar combri lecion velig Sur klique prio na alven better heler do mulam wing kri dentis fores; neiges. Otta velgen dang tablei sigger ha, de jori sesser deferi mand aven taingo, ous pli dat har ber, admit modomme stsa verbie dente \ntescri coninis spubli tudomba prob ettede gileco-assasa cou viden aptett crease \nCarible quito parnace centel darakol tor ald jethim Band lade nirace jusene dentst Atarmi de que che horeko sicars sileat waler sol nu eximpli, derem me golkat wer biesa vendar dar, Proctu vuninne noni, redre de sidire cristu prosin by sollig. Muse, Truppe ournou \n\n\n\n\njula densis que aftes ver der instry tongan prodsle torath sty, fordin fre ate. Folle proxim side o dynied pou 15 monege errout exan arens con sa dio natst by beido side si derion unalle forgat fen kred de ta Commun pet Norgin onicie, quede de finfek, ussied \nsinso destud (oruis qui inic Pardra ver sonang. ledepa ambure istudi extro prose vor ilicad ouptin doglepa, quel hatert fichen hol. Perese hose sund. Inde vean inciat ger, sailie frader asons. Stapper has sill sinizie, que negare aud dre ebien vorwas no denses on Glonst ant. - Poich compo por kal pre 11 Tar buirst pals que sudare. Augenn, end in gland \nslanne (Benthu sudare gue \n\n\ngunder. Orgars Tyrahap ang Leogic \nponfer essa, den faced Horma tion. Son bellaw opecto sung vierar, my laverve ton murrad mi, wel peratra, hosta site bance sust wantion siodu motech nedion, Eveces polembie etito tia pesti. Mankel toma minega obla openbe not pristo stme pectir trong. Ins vesu Pron Conoct cia lazen, clas a danoca in tioda se noment has eirim sigher Dosela sitemus pei (sette ture pares, sie istakt undacep falge. det. Kamika pasit, hest ronseg. Lamadr.\n\n\n\n\n\" > text");
	while (getline(&gline, &m, fp) > -1)
	
	{
		i++;
		gnlline = get_next_line(fd);
		if (strcmp(gnlline, gline))
		{
			printf("Diff in \"%s\" != \"%s\"\n", gnlline, gline);
			m = -1;
			free(gnlline);
			break ;
		}
		else
			printf("%ld:	GNL \"%s\"\n	GL  \"%s\"\n", i, gnlline, gline);
		free(gnlline);
	}
	printf("TEST read from file complete\n");

	free(gline);
	fclose(fp);
	close(fd);

	return (0);
}
*/
